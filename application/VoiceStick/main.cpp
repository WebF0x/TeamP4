/*
 * main.cpp
 * Create a VoiceStick window with the appropriate phonem names
 * Author: alle2004,dupm2216,leta1602,maia2604,poum2319,valp2602
 * Date: Hiver 2015
 * Copyright (c) 2015   Département de génie électrique et génie informatique
 *                       Université de Sherbrooke
*/

#include "VoiceStick.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	VoiceStick *w = new VoiceStick();
    w->show();

    return a.exec();
}
