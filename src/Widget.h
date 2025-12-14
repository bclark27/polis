#ifndef WIDGET_H_
#define WIDGET_H_

#include "comm/Common.h"

#define WIDGET_TYPE_COUNT   (100)
#define RAW_WIDGET_COUNT    (10)
#define WIDGET_IS_RAW(w)    ((w) < (RAW_WIDGET_COUNT))
#define WIDGET_RAND_SEED    (123123)
#define MAX_RECIPE_LEN      (3)
#define MAX_WIDGET_REQ_ITEM_COUNT   (3)
#define MAX_WIDGET_TIME_PRODUCE (10)
#define MAX_WIDGET_DECAY (0.1)
#define MAX_WIDGET_LABOR_REQ (3)

typedef unsigned short Widget;

typedef struct WidgetRecipeReq
{
    Widget widget;
    unsigned int count;
} WidgetRecipeReq;

typedef struct WidgetRecipe
{
    bool raw;
    unsigned int timeToProduce;
    unsigned int labor;
    unsigned int reqsLen;
    WidgetRecipeReq* reqs;
} WidgetRecipe;

typedef struct WidgetDef
{
    float decay;
    float weight; // represents weight, size... basically how hard it is to move around or store
    WidgetRecipe recipe;
} WidgetDef;

void Widget_init();
void Widget_free();

WidgetDef* Widget_getDef(Widget w);

#endif