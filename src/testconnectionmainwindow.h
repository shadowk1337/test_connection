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
  TestConnectionMainWindow(QWidget *parent = nullptr);
  ~TestConnectionMainWindow();

 public:
  void setWindowGeometry(int width, int height);

 public:
  void setConnections();

 public slots:
  void keyPressEvent(QKeyEvent *event);

 private:
  Ui::TestConnectionMainWindow *ui;
  const int _w = 220, _h = 186;
  QPointer<TestConnectionMainWindowContent> content;
  QPointer<NetworkManager> networkManager;
};

class TestConnectionMainWindowContent : public QObject {
  Q_OBJECT

 public:
  TestConnectionMainWindowContent(Ui::TestConnectionMainWindow *ui,
                                  QObject *parent = 0);

 public:
  void setConnections();

 public slots:
  void onButtonPressed();

 private:
  Ui::TestConnectionMainWindow *ui;
  QString _welcomeHeader = "Log in to the site";
  ConnectionLink _siteName = QString("http://vk.com");
};

class NetworkManager : public QObject {
  Q_OBJECT

 public:
  NetworkManager(QObject *parent = 0);
  ~NetworkManager();

 private:
  QPointer<TestNetworkManager> testNetworkManager;
};

#endif  // TESTCONNECTION_H
