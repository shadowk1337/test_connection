#ifndef TESTCONNECTION_H
#define TESTCONNECTION_H

#include "testnetworkmanager.h"

#include <QMainWindow>
#include <QPointer>

class TestConnectionMainWindowContent;
class NetworkManager;

class ConnectionLink : public QUrl {
public:
  ConnectionLink() : QUrl() {}
  ConnectionLink(const QString &url,
                 QUrl::ParsingMode parsingMode = TolerantMode)
      : QUrl(url, parsingMode), _url(url) {}
  ConnectionLink(const QUrl &other) : QUrl(other), _url(other.url()) {}
  ConnectionLink(ConnectionLink &&other) : QUrl(other), _url(other.url()) {}
  ConnectionLink &operator=(ConnectionLink &other) {
    _url = other.url();
    return *this;
  }
  ConnectionLink &operator=(const QString &url) {
    _url = url;
    return *this;
  }
  ConnectionLink &operator=(const ConnectionLink &url) {
    _url = url.url();
    return *this;
  }

public:
  QString parsed();

private:
  QString _url;
};

QT_BEGIN_NAMESPACE
namespace Ui {
class TestConnectionMainWindow;
}
QT_END_NAMESPACE

class TestConnectionMainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit TestConnectionMainWindow(QWidget *parent = nullptr);
  ~TestConnectionMainWindow();

public:
  void setWindowGeometry(int width, int height);

public:
  void setConnections();

public slots:
  void keyPressEvent(QKeyEvent *event);

private:
  Ui::TestConnectionMainWindow *ui;
  const int _w = 300, _h = 186;
  QPointer<TestConnectionMainWindowContent> _windowContent;
};

class TestConnectionMainWindowContent : public QObject {
  Q_OBJECT

public:
  explicit TestConnectionMainWindowContent(Ui::TestConnectionMainWindow *ui,
                                  QObject *parent = 0);

public:
  void fillSiteList();
  void setConnections();

public slots:
  void onComboBoxCurrentIndexChanged(int index);
  void onButtonPressed();

private:
  Ui::TestConnectionMainWindow *ui;
  QPointer<NetworkManager> _networkManager;
  ConnectionLink _siteName = QString("https://account.mail.ru");

  const QString _welcomeHeader = "Log in to the site";
  QList<QString> _siteList = {"vk.com", "mail.ru", "yandex.ru"};

private:
  struct RequestResultWrapper {
    QString content;
    QColor color;
  };

  RequestResultWrapper failure{"Request failed", Qt::red},
      success{"Request success", Qt::green};
};

class NetworkManager : public QObject {
  Q_OBJECT

public:
  explicit NetworkManager(QObject *parent = 0);
  ~NetworkManager();

public:
  TestNetwork::RequestResult
  send(const QString &url, const QString &login, const QString &password);

private:
  QPointer<TestNetworkManager> _testNetworkManager;
};

#endif // TESTCONNECTION_H
