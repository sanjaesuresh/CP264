/*
-------------------------------------
File:    My_Definitions.h
Project: CP264
file description
-------------------------------------
Author:  Heider Ali/Rick Magnotta
ID:      XXXXXXXX
Email:   heali@wlu.ca/rmagnotta@wlu.ca
Version  2019-11-08
Last Modified: 2023-03-17
-------------------------------------
 */
#ifndef MY_DEFINITIONS_H_
#define MY_DEFINITIONS_H_

//#define DEBUG_LEVEL_01  1
//#define DEBUG_LEVEL_02  1

#ifdef TRUE
   #undef TRUE
   #undef FALSE
#endif
#define TRUE  (1==1)
#define FALSE (0==1)

typedef unsigned bool;

#define SUCCESS TRUE;
#define FAILURE FALSE;

//FOUND     = TRUE ;
//NOT_FOUND = FALSE;

#endif /* MY_DEFINITIONS_H_ */
