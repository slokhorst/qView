#ifndef QVGRAPHICSVIEW_H
#define QVGRAPHICSVIEW_H

#include "mainwindow.h"
#include "qvimagecore.h"
#include <QGraphicsView>
#include <QImageReader>
#include <QMimeData>
#include <QDir>
#include <QTimer>
#include <QFileInfo>

class QVGraphicsView : public QGraphicsView
{
    Q_OBJECT

public:
    QVGraphicsView(QWidget *parent = nullptr);

    enum class scaleMode
    {
       resetScale,
       zoom
    };
    Q_ENUM(scaleMode)

    enum class goToFileMode
    {
       constant,
       first,
       previous,
       next,
       last
    };
    Q_ENUM(goToFileMode)

    void zoom(int DeltaY, const QPoint &pos, qreal targetScaleFactor = 0);

    QMimeData* getMimeData() const;
    void loadMimeData(const QMimeData *mimeData);
    void loadFile(const QString &fileName);
    void addRecentFiles();
    void setWindowTitle();

    void resetScale();
    void scaleExpensively(scaleMode mode);
    void originalSize(bool setVariables = true);

    void goToFile(const goToFileMode &mode, int index = 0);

    void loadSettings();

    void jumpToNextFrame();
    void setPaused(const bool &desiredState);
    void setSpeed(const int &desiredSpeed);
    void rotateImage(int rotation);

    const QVImageCore::QVFileDetails& getCurrentFileDetails() const { return imageCore.getCurrentFileDetails(); }
    const QPixmap& getLoadedPixmap() const { return imageCore.getLoadedPixmap(); }
    const QMovie& getLoadedMovie() const { return imageCore.getLoadedMovie(); }

signals:
    void cancelSlideshow();

    void fileLoaded();

    void updatedLoadedPixmapItem();

    void updatedFileInfo();

    void updateRecentMenu();

    void sendWindowTitle(const QString &newTitle);

protected:
    void wheelEvent(QWheelEvent *event) override;

    void resizeEvent(QResizeEvent *event) override;

    void dropEvent(QDropEvent *event) override;

    void dragEnterEvent(QDragEnterEvent *event) override;

    void dragMoveEvent(QDragMoveEvent *event) override;

    void dragLeaveEvent(QDragLeaveEvent *event) override;

    void enterEvent(QEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    bool event(QEvent *event) override;

    void fitInViewMarginless(bool setVariables = true);


private slots:
    void animatedFrameChanged(QRect rect);

    void postLoad();

    void updateLoadedPixmapItem();

    void updateFileInfoDisplays();

    void error(const QString &errorString, const QString &fileName);

private:


    QGraphicsPixmapItem *loadedPixmapItem;
    QRectF adjustedBoundingRect;
    QSize adjustedImageSize;

    QTransform fittedMatrix;
    QTransform scaledMatrix;

    bool isFilteringEnabled;
    bool isScalingEnabled;
    bool isScalingTwoEnabled;
    bool isPastActualSizeEnabled;
    bool isScrollZoomsEnabled;
    bool isLoopFoldersEnabled;
    bool isSaveRecentsEnabled;
    int titlebarMode;
    int cropMode;
    qreal scaleFactor;

    qreal currentScale;
    QSize scaledSize;
    bool isOriginalSize;
    qreal maxScalingTwoSize;
    bool cheapScaledLast;
    bool movieCenterNeedsUpdating;
    QFileInfoList addRecentFileQueue;

    QVImageCore imageCore;

    QTimer *expensiveScaleTimer;
    QTimer *addRecentFilesTimer;
};
#endif // QVGRAPHICSVIEW_H
