#ifndef GLOBALVIEWPARAMS_H
#define GLOBALVIEWPARAMS_H

#include <QObject>
#include <QString>
#include <QVector>

#include "QGCMAVLink.h"
#include "Imagery.h"

class GlobalViewParams : public QObject
{
    Q_OBJECT

public:
    GlobalViewParams();

    bool& displayTerrain(void);
    bool displayTerrain(void) const;

    bool& displayWorldGrid(void);
    bool displayWorldGrid(void) const;

    Imagery::Type& imageryType(void);
    Imagery::Type imageryType(void) const;

    int& followCameraId(void);
    int followCameraId(void) const;

    MAV_FRAME& frame(void);
    MAV_FRAME frame(void) const;

public slots:
    void followCameraChanged(const QString& text);
    void frameChanged(const QString &text);
    void imageryTypeChanged(int index);
    void toggleTerrain(int state);
    void toggleWorldGrid(int state);

signals:
    void followCameraChanged(int systemId);

private:
    bool mDisplayTerrain;
    bool mDisplayWorldGrid;
    Imagery::Type mImageryType;
    int mFollowCameraId;
    MAV_FRAME mFrame;
};

typedef QSharedPointer<GlobalViewParams> GlobalViewParamsPtr;

#endif // GLOBALVIEWPARAMS_H
