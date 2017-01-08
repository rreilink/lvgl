/**
 * @file lv_app_notice.c
 * 
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_app_notice.h"
#if LV_APP_ENABLE != 0

#include "lvgl/lv_objx/lv_rect.h"
#include "lvgl/lv_objx/lv_label.h"

#include "lvgl/lv_misc/anim.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static lv_obj_t * notice_h;

static lv_rects_t notice_rects;
static lv_labels_t notice_labels;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/
void lv_app_notice_init(void)
{
    lv_app_style_t * app_style = lv_app_get_style();

    memcpy(&notice_rects, &app_style->menu_style, sizeof(lv_rects_t));
    notice_rects.round = 5 * LV_DOWNSCALE;
    notice_rects.bcolor = COLOR_WHITE;
    notice_rects.bwidth = 1 * LV_DOWNSCALE;
    notice_rects.bopa = 90;
    notice_rects.light = 5 * LV_DOWNSCALE;

    memcpy(&notice_labels, &app_style->menu_btn_label_style, sizeof(lv_labels_t));
    notice_labels.mid = 0;
    notice_labels.font = LV_APP_FONT_MEDIUM;

    notice_h = lv_rect_create(lv_scr_act(), NULL);
    lv_obj_set_size(notice_h, LV_HOR_RES, LV_VER_RES - app_style->menu_h);
    lv_obj_set_y(notice_h, app_style->menu_h);
    lv_obj_set_click(notice_h, false);
    lv_obj_set_style(notice_h, lv_rects_get(LV_RECTS_TRANSP, NULL));
    lv_rect_set_layout(notice_h, LV_RECT_LAYOUT_COL_R);
}

void lv_app_notice_add(const char * txt)
{
    lv_app_style_t * app_style = lv_app_get_style();

    lv_obj_t * n;
    n = lv_rect_create(notice_h, NULL);
    lv_rect_set_fit(n, true, true);
    lv_obj_set_style(n, &notice_rects);
    lv_obj_set_opa(n, app_style->menu_opa);

    lv_obj_t * l;
    l = lv_label_create(n, NULL);
    lv_label_set_text(l, txt);
    lv_obj_set_style(l, &notice_labels);


    lv_obj_set_parent(notice_h, lv_scr_act());

    lv_rect_set_fit(n, false, false);
#if LV_APP_EFFECT_ANIM != 0 && LV_APP_ANIM_NOTICE != 0
    anim_t a;
    a.var = n;
    a.path = anim_get_path(ANIM_PATH_LIN);
    a.time = LV_APP_ANIM_NOTICE;
    a.act_time = - LV_APP_NOTICE_SHOW_TIME;
    a.playback = 0;
    a.playback_pause = 0;
    a.repeat = 0;
    a.repeat_pause = 0;
    a.end_cb = NULL;
#if LV_APP_EFFECT_OPA_ANIM != 0
    a.fp = (anim_fp_t) lv_obj_set_opar;
    a.start = lv_obj_get_opa(n);
    a.end = OPA_TRANSP;
    anim_create(&a);

    /*Restore the label opacity because the opar anim changes it*/
    lv_obj_set_opa(l, OPA_COVER);

    a.act_time = - LV_APP_NOTICE_SHOW_TIME - LV_APP_ANIM_NOTICE; /*Do the next animation after the opa animation*/
#endif

    a.fp = (anim_fp_t) lv_obj_set_height;
    a.start = lv_obj_get_height(n);
    a.end = 0;
    a.end_cb = lv_obj_del;
    anim_create(&a);
#else
    anim_t a;
    a.var = n;
    a.path = anim_get_path(ANIM_PATH_STEP);
    a.time = LV_APP_ANIM_NOTICE;
    a.act_time = - LV_APP_NOTICE_SHOW_TIME + LV_APP_ANIM_NOTICE;
    a.playback = 0;
    a.playback_pause = 0;
    a.repeat = 0;
    a.repeat_pause = 0;
    a.fp = (anim_fp_t) lv_obj_set_height;
    a.start = lv_obj_get_height(n);
    a.end = lv_obj_get_height(n);
    a.end_cb = lv_obj_del;
    anim_create(&a);
#endif

}
/**********************
 *   STATIC FUNCTIONS
 **********************/
#endif