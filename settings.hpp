//setings.hpp
#ifndef SETTINGS_H
#define SETTINGS_H
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>
#include "input.hpp"

const int Settings_Count = 3;
int Settings_index = 0;

void Settings_Game(const int Center, int *Board_Size, int *Color_index){
    Settings_index = 0; //vorpisi misht sksi arajin toxic
    const bool Sleep_Show = 0;
    Show_Game_Name(Center, Sleep_Show);
    int Settings_Col = Center - 3;    
    std::string Settings[Settings_Count]={"Board Size  _", "Board Color _","Users"};
    const int Color_Count = 8;
    std::string Colors[Color_Count] = {"White  ", "Gray   ", "Blue   ", "Green  ",
                                       "Cyan   ", "Red    ", "Pink   ", "Yellow "};
    
    for(int i = 0; i < Settings_Count; ++i){
        gotoxy(Settings_Col,15 + i);
        Color_Cout(Settings[i],7); std::cout<<"\n";
    }
    gotoxy(Settings_Col, 15 + Settings_index); // arajbayin yntrvac toxy
    Color_Cout(Settings[Settings_index],3);

    gotoxy(Settings_Col + 14, 15 + Settings_index);// yntrvac chapi skzbnarjeqavorum
    Color_Cout(*Board_Size, 5);
    
    gotoxy(Settings_Col + 14, 15 + 1 + Settings_index);
    Color_Cout(Colors[*Color_index],*Color_index);
    
    int Size;
    for(char key_2 = -1; key_2 != 27; ) {
        cbreak();
        key_2 = keypress();

        switch(key_2){
    
            case 'w': case 'W': 
                if(Settings_index != 0){
                    gotoxy(Settings_Col,15 + Settings_index); Color_Cout(Settings[Settings_index],7); 
                    --Settings_index;
                    gotoxy(Settings_Col,15 + Settings_index); Color_Cout(Settings[Settings_index],3);
        
                } else {
                    gotoxy(Settings_Col,15 + Settings_index); Color_Cout(Settings[Settings_index],7);
                    Settings_index = Settings_Count - 1;
                    gotoxy(Settings_Col,15 + Settings_index); Color_Cout(Settings[Settings_index],3);
                
                } break;
            
            case 's': case 'S':
                if(Settings_index != Settings_Count - 1){
                    gotoxy(Settings_Col,15 + Settings_index); Color_Cout(Settings[Settings_index],7);
                    ++Settings_index;
                    gotoxy(Settings_Col,15 + Settings_index) ;Color_Cout(Settings[Settings_index],3);
                } else {
                    gotoxy(Settings_Col,15 + Settings_index); Color_Cout(Settings[Settings_index],7);
                    Settings_index = 0;
                    gotoxy(Settings_Col,15 + Settings_index); Color_Cout(Settings[Settings_index],3);

                } break;

            case 0x0A:// erb sexme nq enter kkatari hamapatasxan indexov "case"-y 
                int min_Board_Size = 2;
                int max_Board_Size = 6;
                                
                switch(Settings_index){                    
                    case 0:
                        for(char key = -1; key != 10;  ){
                            cbreak();
                            key = keypress();
                            switch(key){
                                case 'W': case 'w':
                                    if(*Board_Size == max_Board_Size){
                                        *Board_Size = min_Board_Size;
                                        gotoxy(Settings_Col + 14, 15 + Settings_index);
                                        Color_Cout(*Board_Size, 5);
                                    } else {
                                        ++*Board_Size;
                                        gotoxy(Settings_Col + 14, 15 + Settings_index);
                                        Color_Cout(*Board_Size, 5);
                                    }
                                   break;
                                
                                case 'S': case 's':
                                   if(*Board_Size == min_Board_Size){
                                       *Board_Size = max_Board_Size;
                                       gotoxy(Settings_Col + 14, 15 + Settings_index);
                                       Color_Cout(*Board_Size, 5);
                                   } else {
                                       --*Board_Size;
                                       gotoxy(Settings_Col + 14, 15 + Settings_index);
                                       Color_Cout(*Board_Size, 5);
                                   }
                                  break;
                                case 10:
                                  std::cout<<"\n\n";
                                  break;
                            }                       
                     } break;
                    case 1:
                        for(char key = -1; key != 10;  ){
                            cbreak();
                            key = keypress();
                            switch(key){
                                case 'W': case 'w':                                
                                    if(*Color_index == Color_Count-1){
                                        *Color_index = 0;
                                        gotoxy(Settings_Col + 14, 15 + Settings_index);
                                        Color_Cout(Colors[*Color_index],*Color_index);
                                    } else {
                                        ++*Color_index;
                                        gotoxy(Settings_Col + 14, 15 + Settings_index);
                                        Color_Cout(Colors[*Color_index],*Color_index);
                                    }
                                    break;
                       
                                case 'S': case 's':
                                    if(*Color_index == 0){
                                       *Color_index = Color_Count - 1;
                                       gotoxy(Settings_Col + 14, 15 + Settings_index);
                                        Color_Cout(Colors[*Color_index],*Color_index); 
                                    } else {
                                       --*Color_index;
                                       gotoxy(Settings_Col + 14, 15 + Settings_index);
                                       Color_Cout(Colors[*Color_index],*Color_index); 
                                    }
                                   break;
                        
                            }
                        }  break; 

                 case 2:
                        break;
                          
                } 
        }
    }
normal();
}

#endif //SETTINGS_H
