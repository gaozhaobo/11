#include "quest_robot_api_client.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>
#include <QUrl>

QuestRobotApiClient::QuestRobotApiClient(QObject *parent)
    : QObject(parent)
    , _serverBaseUrl("http://127.0.0.1:5555")
    , _network(new QNetworkAccessManager(this))
    , _pollTimer(new QTimer(this))
    , _lastTimestamp(0)
{
    connect(_pollTimer, &QTimer::timeout, this, &QuestRobotApiClient::pollLatestCommand);
    connect(_network, &QNetworkAccessManager::finished, this, &QuestRobotApiClient::onReplyFinished);
}

void QuestRobotApiClient::setServer(const QString &serverBaseUrl)
{
    _serverBaseUrl = serverBaseUrl;
}

void QuestRobotApiClient::setPollingIntervalMs(int intervalMs)
{
    _pollTimer->setInterval(intervalMs);
}

void QuestRobotApiClient::start()
{
    if (_pollTimer->interval() <= 0)
    {
        _pollTimer->setInterval(50); // default 20Hz
    }

    _pollTimer->start();
    emit statusMessage("Quest robot API polling started.");
}

void QuestRobotApiClient::stop()
{
    _pollTimer->stop();
    emit statusMessage("Quest robot API polling stopped.");
}

void QuestRobotApiClient::pollLatestCommand()
{
    const QUrl url(_serverBaseUrl + "/api/robot/latest");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("application/json"));
    _network->get(request);
}

void QuestRobotApiClient::onReplyFinished(QNetworkReply *reply)
{
    if (!reply)
    {
        return;
    }

    if (reply->error() != QNetworkReply::NoError)
    {
        emit statusMessage(QString("Quest robot API error: %1").arg(reply->errorString()));
        reply->deleteLater();
        return;
    }

    const QByteArray payload = reply->readAll();
    const QJsonDocument document = QJsonDocument::fromJson(payload);
    if (!document.isObject())
    {
        reply->deleteLater();
        return;
    }

    const QJsonObject root = document.object();
    const qint64 timestamp = static_cast<qint64>(root.value("timestamp").toDouble(0));
    const qint64 nowMs = QDateTime::currentMSecsSinceEpoch();
    constexpr qint64 kMaxCommandAgeMs = 1000; // reject stale commands (e.g. Qt restarted)
    if (timestamp <= 0 || timestamp == _lastTimestamp || (nowMs - timestamp) > kMaxCommandAgeMs)
    {
        reply->deleteLater();
        return;
    }

    const QJsonObject targetPose = root.value("target_pose").toObject();
    if (targetPose.isEmpty())
    {
        reply->deleteLater();
        return;
    }

    _lastTimestamp = timestamp;

    const int robotIndex = root.value("robot_index").toInt(1);
    emit commandReceived(robotIndex,
                         targetPose.value("x").toDouble(0.0),
                         targetPose.value("y").toDouble(0.0),
                         targetPose.value("z").toDouble(0.0),
                         targetPose.value("qx").toDouble(0.0),
                         targetPose.value("qy").toDouble(0.0),
                         targetPose.value("qz").toDouble(0.0),
                         targetPose.value("qw").toDouble(1.0),
                         timestamp);
    reply->deleteLater();
}
