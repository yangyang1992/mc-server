#pragma once
#ifndef TIME_FRAME_H
#define TIME_FRAME_H

static char* frame_name;

typedef enum INDENTITY
{
	int_type,
	char_type,
	byte_type
} IDT;

typedef struct HEAD
{
	int size;
	char* name;
} HEAD;

typedef struct FIELD
{
	int size;
	char* name;
	char* type;
	int offset;
} FLD;

typedef struct FLD_FRM
{
	FLD* fld;
	struct FLD_FRM* next;
} FLD_FRM;

typedef struct FRAME
{
	FLD_FRM* fld_frm;
	int fld_size;
	struct FRAME* child;
	int child_size;
} FRM;

char* get_var(char* yytext);
char* get_type_name(IDT idt);
IDT get_INTDECL();
IDT get_CHARDECL();
IDT get_BYTEDECL();

HEAD* init_head(char* name, int size);

FLD* init_fld(HEAD* head, char* type, int num);

FRM* init_frm_by_fld(FLD* fld);

void add_fld2frm(FRM* frm, FLD* fld);

void add_child2frm(FRM* frm, FRM* sub);

void show_fld_frm(FRM* frm);

void show_child_frm(FRM* frm);
#endif
