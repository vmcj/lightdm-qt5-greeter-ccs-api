#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDateTime>
#include <QFile>


class Downloader : public QObject {
Q_OBJECT
public:
    explicit Downloader(QObject *parent = nullptr);

    void doDownload(const QString &url, QString to);

signals:

    void imageDownloaded(QString path);

private slots:

    void replyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager *manager;
    QString target;
};

#endif // DOWNLOADER_H
