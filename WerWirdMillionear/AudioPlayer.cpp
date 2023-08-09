// AudioPlayer.cpp
/*
#include "AudioPlayer.h"
#include <QCoreApplication>
#include <VLCQtCore/Common.h>
#include <VLCQtCore/Media.h>
#include <VLCQtCore/MediaPlayer.h>
#include <VLCQtCore/Instance.h>

AudioPlayer::AudioPlayer(QWidget *parent)
    : QWidget(parent)
{
    VlcCommon::setPluginPath("C:/Users/houss/OneDrive/Documents/wer-wird-millionear2/VLC-Qt_1.1.0_win64_msvc2015/bin/plugins");
    vlcInstance = new VlcInstance(VlcCommon::args(), this); // Create a VlcInstance
    mediaPlayer = new VlcMediaPlayer(vlcInstance);
}

AudioPlayer::~AudioPlayer()
{
    delete mediaPlayer;
    delete vlcInstance; // Remember to delete the VlcInstance
}

void AudioPlayer::playAudio(const QString &audioFilePath)
{
    VlcMedia *media = new VlcMedia(audioFilePath, true, vlcInstance); // Use the VlcInstance here
    mediaPlayer->open(media);
    mediaPlayer->play();
}
*/
