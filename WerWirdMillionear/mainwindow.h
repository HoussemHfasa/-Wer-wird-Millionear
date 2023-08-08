#include <QMainWindow>
#include <QLabel>
#include <QStackedWidget>
#include <QModelIndexList>
#include <QStandardItemModel>
#include <QPushButton>
#include <QLineEdit>
#include <QMainWindow>
#include <QComboBox>
#include <GameSession.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
void handleAnswerClick(char selectedAnswer);


private slots:
    void on_StartButton_clicked();
    void on_BestenlisteButton_clicked();
    void on_SpielStartButton_clicked();
    void on_Answer1_4_clicked();
    void Combobox();
    void onCategoryChanged(QString category);
    void onDifficultyChanged(QString difficulty);
    void on_Answer2_clicked();
    void on_Answer3_clicked();
    void on_Answer4_clicked();
    void on_spielanleitungButton_clicked();

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
    QComboBox *comboBox_Kategorie;
    QComboBox *comboBox_Schwierigkeitsgrad;
    vector<Frage> fragen;
    int aktuelleFrageIndex;
    SpielanleitungPage *spielanleitungPage;
};
