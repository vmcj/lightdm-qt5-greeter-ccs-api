//
// Created by Nicky Gerritsen on 08/11/2021.
//

#ifndef CCS_CONTEST_WATCHER_H
#define CCS_CONTEST_WATCHER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTimer>

class CcsContestWatcher : public QObject {
Q_OBJECT
public:
    explicit CcsContestWatcher(QObject *parent = nullptr);

    void startWatching(QString u);

signals:

    void contestAboutToStart();

    void contestStarted();

private slots:

    void checkCcsUrl();

    void replyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    QTimer *timer;
    QString url;
    static const int ABOUT_TO_START_MSEC = 15000;
    static const int START_MINIMUM_MSEC = 500;
};

#endif // CCS_CONTEST_WATCHER_H
