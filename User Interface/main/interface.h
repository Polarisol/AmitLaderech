//==============================================================================
//
// Title:		interface.h
// Purpose:		A short description of the interface.
//
// Created on:	20-Apr-17 at 19:36:38 by .
// Copyright:	. All Rights Reserved.
//
//==============================================================================

#ifndef __interface_H__
#define __interface_H__

#ifdef __cplusplus
    extern "C" {
#endif

#include "cvidef.h"
// CONSTANTS
		#define SOLDIER "Database\\soldier.ini"
		#define MENTOR  "Database\\mentor.ini"
		#define GUIDE   "Database\\guide.ini"
		#define CONFIG  "Database\\config.ini"
		#define GROUP   "Database\\group.ini"
		#define SIZE 300
		
// External variables
    static int pMain, pActivity, pGuide, pNewGuide, pMentor, pNewMent, pSoldier, pNewSold, pEditTL, pTable, pGroup, pNewGroup;
	static char id[SIZE], currentDate[50], currentTime[50];
	static char **tagName,**tagValue,**ids,**output; 
	int recordAmount;
	int fieldAmount;
	int ctrlArray;
	int hr, min, sec;
	int day, month, year;
//==============================================================================
// Global functions

void initialize(char database[],char dir[]);
void finalize();
void addMember(char dir[],char database[],int panel,int ctrlArray);
int getIndexOfControl(int panel,int ctrlArray,int count,char controlName[]);
void showMember(int panel,char dir[],char database[],char record[],int ctrlArray);
void connectIDtoName(char dir[],char database[],char record[],char fullName[]);
int connectNametoID(char dir[],char database[],char record[],char fullName[]); 
void createTable(char dir[],char database[], char **ids, int rows,int panel,int control);
int connectNametoIDS(char **records,char fullName[]);
int search(char searchBy[],char val[],char **output);
void clockDate();
void restoreSearch();
void displayGroupPanel(char groupName[]);
void searchSoldier(char mentorName[],char soldierName[]);
void searchFor(char dir[],char database[], char fieldName[], char valToCmp[]);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __interface_H__ */
