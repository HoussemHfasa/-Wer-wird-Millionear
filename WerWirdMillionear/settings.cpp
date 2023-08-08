#include "settings.h"
#include "ui_settings.h"

settings::settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
}

settings::~settings()
{
    delete ui;
}

void settings::on_sliderProgress_sliderMoved(int position)
{

}


void settings::on_sliderVolume_sliderMoved(int position)
{

}

