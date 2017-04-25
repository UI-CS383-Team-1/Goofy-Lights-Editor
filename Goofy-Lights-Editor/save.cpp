#include "save.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QDebug>
#include <QApplication>
#include "mainwindow.cpp"

void save(){

    QFile file(save_location);
            if(!file.open(QIODevice::WriteOnly)){
                QMessageBox::information(this, tr("Error"), file.errorString());
                return;
            }
            else{

                //Write file *phew*
                for(unsigned int i = 0; i < animation.size(); i++){
                    file.write(std::to_string(animation[i].time).c_str());
                    file.write("\n");
                    for(int r = 0; r < 10; r++){
                        for(int c = 0; c < 20; c++){
                            //Write rgb into file
                            file.write(std::to_string(animation[i].frame[r][c].r).c_str());
                            file.write(" ");
                            file.write(std::to_string(animation[i].frame[r][c].g).c_str());
                            file.write(" ");
                            file.write(std::to_string(animation[i].frame[r][c].b).c_str());
                            file.write(" ");
                        }
                        file.write("\n");
                    }
                }
            }


}
