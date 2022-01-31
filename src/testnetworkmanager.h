#ifndef TESTNETWORKMANAGER_H
#define TESTNETWORKMANAGER_H

#include <QNetworkAccessManager>
#include <QPointer>
#include <QStringList>
#include <QUrlQuery>

class QtCurlManager;
class CookiesHandler;

QT_BEGIN_NAMESPACE
namespace TestNetwork {
typedef bool CURLOPT_POST;
typedef bool CURLOPT_FOLLOWACTION;
typedef bool CURLOPT_FAILONERROR;
typedef bool CURLOPT_SSL_VERIFYHOST;
typedef bool CURLOPT_SSL_VERIFYPEER;
typedef bool CURLOPT_RETURNTRANSFER;
typedef bool CURLOPT_FOLLOWLOCATION;
typedef QUrlQuery CURLOPT_URL;
typedef QStringList CURLOPT_HTTPHEADER;
typedef QString CURLOPT_COOKIEJAR;
typedef QString CURLOPT_USERAGENT;
typedef QString CURLOPT_REFERER;

struct QtCurlOptions {
  CURLOPT_URL url;
};

struct RequestPackage {
  QString url;
  QString login;
  QString password;
};
}  // namespace TestNetwork
QT_END_NAMESPACE

class TestNetworkManager : public QObject {
  Q_OBJECT

 public:
  TestNetworkManager(QObject *parent = 0);
  ~TestNetworkManager();

  enum RequestResult {
    FAILURE = 0,
    SUCCESS,
  };

 public:
  RequestResult send(const TestNetwork::RequestPackage &package);

 private:
  QPointer<CookiesHandler> _cookiesHandler;
  QPointer<QtCurlManager> _curlManager;
};

class QtCurlManager : public QObject {
  Q_OBJECT

 public:
  QtCurlManager(QObject *parent = 0);

 public:
  void setOptions();
  void setPackage(const TestNetwork::RequestPackage &package);

 private:
  TestNetwork::RequestPackage _package;
};

class CookiesHandler : public QObject {
  Q_OBJECT

 public:
  CookiesHandler(QObject *parent = 0);
  ~CookiesHandler();

 public:
  void sendGetRequest(const QUrl &url, const QByteArray &data);
  void sendPostRequest(const QUrl &url, const QByteArray &data);

 private:
  QPointer<QNetworkAccessManager> _networkManager;
};

#endif  // TESTNETWORKMANAGER_H
