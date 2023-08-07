#include <QMainWindow>
#include <QLabel>
#include <QStackedWidget>
#include <QModelIndexList>
#include <QStandardItemModel>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_StartButton_clicked();
    void on_BestenlisteButton_clicked();

    void on_SpielStartButton_clicked();

    void on_Answer1_4_clicked();

    void on_listView_indexesMoved(const QModelIndexList &indexes);

private:
    Ui::MainWindow *ui;
    QLabel *imageLabel;
    QStandardItemModel *playerModel;
    QStackedWidget *stackedWidget;
    QPushButton* Answer1;
    QPushButton* Answer2;
    QPushButton* Answer3;
    QPushButton* Answer4;
    QLabel* getFrage;
    QLineEdit* input_nickname;

};
