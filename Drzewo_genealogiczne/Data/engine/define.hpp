//**********************************************************************************************************************************************************//
//	Plik: definition.hpp																									Data_utworzenia: 12-03-2018		//
//	data_aktualizacji: |	Autor:		|					Opis:																							//
//	15-03-2018				Lukasz			Dodanie satlych predefiniowalnych:																				//
//											- load_files - do odczytu z pliku																				//
//											- save_files - do zapisu do pliku																				//
//											- add_person - do dodawania nowych osob do drzewa																//
//											- delete_person - do usuwania osob z drzewa																		//
//											- update_person - do edytowania osob w drezwie																	//
//**********************************************************************************************************************************************************//
#ifndef DEFINITION_HPP
#define DEFINITION_HPP
#include <sstream>
#include <conio.h>
#define size_menu				10
#define Menu_glowne				0
#define load_files				10
#define save_files				11
#define add_person				12
#define delete_person			13
#define update_person			14
#define tree					15
#define search					16
#define search_tree				17
#define	new_tree				18
#define delete_tree				19
#define load_content_tree		20
#define searchperson			21
#define Menu_pewnosci			22
#define M_zarzadzaniatree		23
#define M_zarzadzaniapersonem	24
#define exit					100
//nazwa pliku do zapisu
#define file_save "plik2.txt"
#define file_load "plik1.txt"
#define file_list_tree "plik3.txt"
//stale typow relacji
#define r_parents 1
#define r_sibling 2
#define r_partner 3
#define r_null 4
#define r_chlidren 5
//stale odnosnie dat
#define D_brith 1
#define D_death 2
//stale odnoscie pluci
#define woman 1
#define man 0
//satle odnosnie sterowania wyswietleniem
#define view_sort 1
#define view_search 2
#define sort_first_name 3
#define sort_last_name 4
#define sort_id 0
#define sort_date_brith 5
#define sort_date_death 6
//stale odnosnie koment systemowych
#define cmd_del_tree "del "
//stale obslugi klawiszy
#define vkdelete 99
#define vkcapslook 300 //dziala tylko trzymanie
#define vklshift 300
#define vkrshift 300
#define vkspace 101
#define vkdown 102
#define vkup 103
#define vkreturn 104
#define vkescape 105
#define vka 106
#define vkb 107
#define vkc 108
#define vkd 109
#define vke 110
#define vkf 111
#define vkg 112
#define vkh 113
#define vki 114
#define vkj 115
#define vkk 116
#define vkl 117
#define vkm 118
#define vkn 119
#define vko 120
#define vkp 121
#define vkq 122
#define vkr 123
#define vks 124
#define vkt 125
#define vku 126
#define vkw 127
#define vkv 128
#define vkx 129
#define vky 130
#define vkz 131
#define vk0 132
#define vk1 133
#define vk2 134
#define vk3 135
#define vk4 136
#define vk5 137
#define vk6 138
#define vk7 139
#define vk8 140
#define vk9 141
#define vkA 406
#define vkB 407
#define vkC 408
#define vkD 409
#define vkE 410
#define vkF 411
#define vkG 412
#define vkH 413
#define vkI 414
#define vkJ 415
#define vkK 416
#define vkL 417
#define vkM 418
#define vkN 419
#define vkO 420
#define vkP 421
#define vkQ 422
#define vkR 423
#define vkS 424
#define vkT 425
#define vkU 426
#define vkW 427
#define vkV 428
#define vkX 429
#define vkY 430
#define vkZ 431
#define vka1 706
#define vkb1 707
#define vkc1 708
#define vkd1 709
#define vke1 710
#define vkf1 711
#define vkg1 712
#define vkh1 713
#define vki1 714
#define vkj1 715
#define vkk1 716
#define vkl1 717
#define vkm1 718
#define vkn1 719
#define vko1 720
#define vkp1 721
#define vkq1 722
#define vkr1 723
#define vks1 724
#define vkt1 725
#define vku1 726
#define vkw1 727
#define vkv1 728
#define vkx1 729
#define vky1 730
#define vkz1 731
#define vka2 1006
#define vkb2 1007
#define vkc2 1008
#define vkd2 1009
#define vke2 1010
#define vkf2 1011
#define vkg2 1012
#define vkh2 1013
#define vki2 1014
#define vkj2 1015
#define vkk2 1016
#define vkl2 1017
#define vkm2 1018
#define vkn2 1019
#define vko2 1020
#define vkp2 1021
#define vkq2 1022
#define vkr2 1023
#define vks2 1024
#define vkt2 1025
#define vku2 1026
#define vkw2 1027
#define vkv2 1028
#define vkx2 1029
#define vky2 1030
#define vkz2 1031
//wartosc id menu
#define id_menu_MenuGlowne			0
#define id_menu_Menu_pewnosci		3
#define id_menu_zarzadzaniadrzewem	1
#define id_menu_zarzadzaniapersonem 7
#define id_menu_MenuSearchTree		4
#define id_menu_MenuNewTree			1
#define id_menu_MenuSearchPerson	5
#define id_menu_Menuedycjipersona	8
#endif // !DEFINITION_HPP
