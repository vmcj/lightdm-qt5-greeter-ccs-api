//
// Created by Nicky Gerritsen on 08/11/2021.
//

#include "downloader.h"

Downloader::Downloader(QObject *parent) : QObject(parent) {
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply * )), this, SLOT(replyFinished(QNetworkReply * )));
}

void Downloader::doDownload(const QString &url, QString to) {
    target = std::move(to);
    manager->get(QNetworkRequest(QUrl(url)));
}

void Downloader::replyFinished(QNetworkReply *reply) {
    if (reply->error()) {
        qDebug() << "ERROR downloading!";
        qDebug() << reply->errorString();
    } else {
        auto *file = new QFile(target);
        if (file->open(QFile::WriteOnly | QFile::Append)) {
            file->write(reply->readAll());
            file->flush();
            file->close();
        }
        delete file;

        emit imageDownloaded(target);
    }

    reply->deleteLater();
}