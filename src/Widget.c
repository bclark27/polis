#include "Widget.h"

////////////
//  VARS  //
////////////

static bool initDone = false;
static WidgetDef defs[WIDGET_TYPE_COUNT];

////////////////////
//  PUBLIC FUNCS  //
////////////////////

void Widget_init()
{
    if (initDone) return;
    initDone = true;

    memset(defs, 0, sizeof(defs));
    srand(WIDGET_RAND_SEED);
    for (Widget w = 0; w < WIDGET_TYPE_COUNT; w++)
    {
        WidgetDef* d = &defs[w];
        bool raw = WIDGET_IS_RAW(w);
        d->recipe.raw = raw;
        d->decay = rand() / (double)RAND_MAX;
        d->weight = rand() / (double)RAND_MAX;

        if (!raw)
        {
            unsigned int len = (rand() % MIN(w, MAX_RECIPE_LEN)) + 1;
            d->recipe.reqsLen = len;
            WidgetRecipeReq* reqs = calloc(len, sizeof(WidgetRecipeReq));
            d->recipe.reqs = reqs;
            d->recipe.timeToProduce = (rand() % (MAX_WIDGET_TIME_PRODUCE + 1));
            d->recipe.labor = (rand() % MAX_WIDGET_LABOR_REQ) + 1;
            for (int k = 0; k < len; k++)
            {
                WidgetRecipeReq* req = &reqs[k];
                req->count = (rand() % MAX_WIDGET_REQ_ITEM_COUNT) + 1;
                req->widget = rand() % w;
            }
        }
    }
}

void Widget_free()
{
    if (!initDone) return;
    initDone = false;

    for (Widget w = 0; w < WIDGET_TYPE_COUNT; w++)
    {
        WidgetDef* d = &defs[w];
        if (d->recipe.reqs) free(d->recipe.reqs);
    }
}

WidgetDef* Widget_getDef(Widget w)
{
    if (w < WIDGET_TYPE_COUNT)
        return &defs[w];
    return NULL;
}
