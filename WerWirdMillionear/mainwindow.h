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
    void on_spielanleitungButton_clicked();
    void onCategoryChanged(QString category);
    void onDifficultyChanged(QString difficulty);
    void on_fiftyFifty_clicked();
    void on_audience_clicked();
    void on_phone_clicked();
    void on_Zurueckstartseite_2_clicked();

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
    int currentscore;
    QLabel *e100Label;
    QLabel *e200Label;
    QLabel *e300Label;
    QLabel *e500Label ;
    QLabel *e1000Label;
    QLabel *e2000Label ;
    QLabel *e4000Label ;
    QLabel *e8000Label ;
    QLabel *e16000Label ;
    QLabel *e32000Label ;
    QLabel *e64000Label ;
    QLabel *e125000Label;
    QLabel *e250000Label ;
    QLabel *e500000Label ;
    QLabel *e1000000Label ;
};
