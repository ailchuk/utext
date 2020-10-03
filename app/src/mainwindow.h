#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFont>
#include <QFontDialog>
#include <QColor>
#include <QColorDialog>
#include <QFileSystemModel>
#include <QLabel>
#include <QWidget>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void createTreeView();

private slots:
    void showCursorPos();

    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionBackground_Color_triggered();

    void on_actionDark_theme_triggered();

    void on_actionLight_theme_triggered();

    void on_treeView_doubleClicked(const QModelIndex &idx);

private:
    Ui::MainWindow *m_ui;
    QString m_file_path;
    QFileSystemModel *m_model;

};
#endif // MAINWINDOW_H
