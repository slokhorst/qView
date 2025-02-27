#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qvinfodialog.h"
#include <QMainWindow>
#include <QShortcut>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void refreshProperties();

    void setWindowSize();

    const bool& getIsPixmapLoaded() const;

    void setJustLaunchedWithImage(bool value);

    QScreen *screenAt(const QPoint &point);

    void pickFile();

public slots:
    void openFile(const QString &fileName);

    void slideshowAction();

    void cancelSlideshow();

    void fileLoaded();

protected:
    void contextMenuEvent(QContextMenuEvent *event) override;

    void showEvent(QShowEvent *event) override;

    void closeEvent(QCloseEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseDoubleClickEvent(QMouseEvent *event) override;

private slots:

    void loadSettings();

    void on_actionOpen_triggered();

    void on_actionAbout_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionOptions_triggered();

    void on_actionPrevious_File_triggered();

    void on_actionNext_File_triggered();

    void on_actionOpen_Containing_Folder_triggered();

    void on_actionWelcome_triggered();

    void on_actionRotate_Right_triggered();

    void on_actionRotate_Left_triggered();

    void on_actionMirror_triggered();

    void on_actionFlip_triggered();

    void on_actionZoom_In_triggered();

    void on_actionZoom_Out_triggered();

    void on_actionReset_Zoom_triggered();

    void updateRecentsMenu();

    void openRecent(int i);

    void clearRecent();

    void on_actionProperties_triggered();

    void on_actionFull_Screen_triggered();

    void on_actionOriginal_Size_triggered();

    void on_actionNew_Window_triggered();

    void on_actionSlideshow_triggered();

    void on_actionPause_triggered();

    void on_actionNext_Frame_triggered();

    void on_actionReset_Speed_triggered();

    void on_actionDecrease_Speed_triggered();

    void on_actionIncrease_Speed_triggered();

    void on_actionSave_Frame_As_triggered();

    void on_actionQuit_triggered();

    void on_actionFirst_File_triggered();

    void on_actionLast_File_triggered();

    void on_actionOpen_URL_triggered();

private:
    Ui::MainWindow *ui;

    void loadShortcuts();

    QMenu *contextMenu;
    QMenu *recentFilesMenu;

    QTimer *slideshowTimer;
    QList<QAction*> recentItems;

    QShortcut *escShortcut;

    QVInfoDialog *info;

    int windowResizeMode;
    bool justLaunchedWithImage;
    qreal maxWindowResizedPercentage;
    bool isSaveRecentsEnabled;
};

#endif // MAINWINDOW_H
