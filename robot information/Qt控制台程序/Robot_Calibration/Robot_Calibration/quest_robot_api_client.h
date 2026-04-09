#ifndef QUEST_ROBOT_API_CLIENT_H
#define QUEST_ROBOT_API_CLIENT_H

#include <QObject>
#include <QString>

class QNetworkAccessManager;
class QNetworkReply;
class QTimer;

class QuestRobotApiClient : public QObject
{
    Q_OBJECT
public:
    explicit QuestRobotApiClient(QObject *parent = nullptr);

    void setServer(const QString &serverBaseUrl);
    void setPollingIntervalMs(int intervalMs);
    void start();
    void stop();

signals:
    void commandReceived(int robotIndex,
                         double x, double y, double z,
                         double qx, double qy, double qz, double qw,
                         qint64 timestamp);
    void statusMessage(const QString &message);

private slots:
    void pollLatestCommand();
    void onReplyFinished(QNetworkReply *reply);

private:
    QString _serverBaseUrl;
    QNetworkAccessManager *_network;
    QTimer *_pollTimer;
    qint64 _lastTimestamp;
};

#endif // QUEST_ROBOT_API_CLIENT_H
