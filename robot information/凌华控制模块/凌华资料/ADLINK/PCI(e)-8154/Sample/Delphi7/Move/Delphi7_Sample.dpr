program Delphi7_Sample;

uses
  Forms,
  Main in 'Main.pas' {Form1},
  APS168 in '..\..\..\..\APS Library\Include\APS168.pas',
  APS_Define in '..\..\..\..\APS Library\Include\APS_Define.pas';

{$R *.res}
begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
