#include "testconnectionmainwindow.h"

#include <QSizePolicy>
#include <QtGlobal>
#include <QtWidgets>

#include "ui_testconnectionmainwindow.h"

QString ConnectionLink::parsed() { return _url; }

TestConnectionMainWindow::TestConnectionMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::TestConnectionMainWindow) {
  ui->setupUi(this);
  _windowContent = new TestConnectionMainWindowContent(ui);
  setWindowGeometry(_w, _h);
  setConnections();
}

TestConnectionMainWindow::~TestConnectionMainWindow() { delete ui; }

void TestConnectionMainWindow::setWindowGeometry(int width, int height) {
  const QRect &r = QGuiApplication::primaryScreen()->availableGeometry();
  move(qAbs(r.width() - width) / 2, qAbs(r.height() - height) / 2);
  setFixedSize(_w, _h);
  this->statusBar()->setSizeGripEnabled(false);
}

void TestConnectionMainWindow::setConnections() {}

void TestConnectionMainWindow::keyPressEvent(QKeyEvent *event) {
  if (!ui->pushButton->isEnabled()) {
    return;
  }
  if (event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return) {
    _windowContent->onButtonPressed();
  }
}

TestConnectionMainWindowContent::TestConnectionMainWindowContent(
    Ui::TestConnectionMainWindow *ui, QObject *parent)
    : QObject(parent) {
  this->ui = ui;
  _networkManager = new NetworkManager();
  this->ui->label->setText(_welcomeHeader + " " + _siteName.toString());
  fillSiteList();
  setConnections();
}

void TestConnectionMainWindowContent::fillSiteList() {
  ui->comboBox->addItem("None");
  qSort(_siteList);
  for (const QString &site : _siteList) {
    ui->comboBox->addItem(site);
  }
}

void TestConnectionMainWindowContent::setConnections() {
  connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this,
          SLOT(onComboBoxCurrentIndexChanged(int)));
  connect(ui->pushButton, &QPushButton::pressed, this,
          &TestConnectionMainWindowContent::onButtonPressed);
}

void TestConnectionMainWindowContent::onComboBoxCurrentIndexChanged(int index) {
  ui->pushButton->setEnabled(index ? true : false);
}

void TestConnectionMainWindowContent::onButtonPressed() {
  QString login = ui->lineEdit_login->text();
  QString password = ui->lineEdit_password->text();
  qDebug() << "LOGIN: " << login << "PASSWORD: " << password;
  _networkManager->send(_siteName.toString(), login, password);
}

NetworkManager::NetworkManager(QObject *parent)
    : QObject(parent), testNetworkManager(new TestNetworkManager) {}

NetworkManager::~NetworkManager() {}

TestNetworkManager::RequestResult
NetworkManager::send(const QString &url, const QString &login,
                     const QString &password) {}
