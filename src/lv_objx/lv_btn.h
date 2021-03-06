/**
 * @file lv_btn.h
 *
 */

#ifndef LV_BTN_H
#define LV_BTN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifdef LV_CONF_INCLUDE_SIMPLE
#include "lv_conf.h"
#else
#include "../../../lv_conf.h"
#endif

#if LV_USE_BTN != 0

/*Testing of dependencies*/
#if LV_USE_CONT == 0
#error "lv_btn: lv_cont is required. Enable it in lv_conf.h (LV_USE_CONT  1) "
#endif

#include "lv_cont.h"
#include "../lv_core/lv_indev.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/* Button states
 * It can be used not only by buttons but other button-like objects too*/
enum {
    LV_BTN_STATE_REL,
    LV_BTN_STATE_PR,
    LV_BTN_STATE_TGL_REL,
    LV_BTN_STATE_TGL_PR,
    LV_BTN_STATE_INA,
    LV_BTN_STATE_NUM,
};
typedef uint8_t lv_btn_state_t;

/*Data of button*/
typedef struct
{
    lv_cont_ext_t cont; /*Ext. of ancestor*/
    /*New data for this type */
    const lv_style_t * styles[LV_BTN_STATE_NUM]; /*Styles in each state*/
#if LV_BTN_INK_EFFECT
    uint16_t ink_in_time;   /*[ms] Time of ink fill effect (0: disable ink effect)*/
    uint16_t ink_wait_time; /*[ms] Wait before the ink disappears */
    uint16_t ink_out_time;  /*[ms] Time of ink disappearing*/
#endif
    lv_btn_state_t state : 3; /*Current state of the button from 'lv_btn_state_t' enum*/
    uint8_t toggle : 1; /*1: Toggle enabled*/
} lv_btn_ext_t;

/*Styles*/
enum {
    LV_BTN_STYLE_REL,
    LV_BTN_STYLE_PR,
    LV_BTN_STYLE_TGL_REL,
    LV_BTN_STYLE_TGL_PR,
    LV_BTN_STYLE_INA,
};
typedef uint8_t lv_btn_style_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a button objects
 * @param par pointer to an object, it will be the parent of the new button
 * @param copy pointer to a button object, if not NULL then the new object will be copied from it
 * @return pointer to the created button
 */
lv_obj_t * lv_btn_create(lv_obj_t * par, const lv_obj_t * copy);

/*=====================
 * Setter functions
 *====================*/

/**
 * Enable the toggled states. On release the button will change from/to toggled state.
 * @param btn pointer to a button object
 * @param tgl true: enable toggled states, false: disable
 */
void lv_btn_set_toggle(lv_obj_t * btn, bool tgl);

/**
 * Set the state of the button
 * @param btn pointer to a button object
 * @param state the new state of the button (from lv_btn_state_t enum)
 */
void lv_btn_set_state(lv_obj_t * btn, lv_btn_state_t state);

/**
 * Toggle the state of the button (ON->OFF, OFF->ON)
 * @param btn pointer to a button object
 */
void lv_btn_toggle(lv_obj_t * btn);

/**
 * Set the layout on a button
 * @param btn pointer to a button object
 * @param layout a layout from 'lv_cont_layout_t'
 */
static inline void lv_btn_set_layout(lv_obj_t * btn, lv_layout_t layout)
{
    lv_cont_set_layout(btn, layout);
}

/**
 * Set the fit policy in all 4 directions separately.
 * It tell how to change the button size automatically.
 * @param btn pointer to a button object
 * @param left left fit policy from `lv_fit_t`
 * @param right right fit policy from `lv_fit_t`
 * @param top bottom fit policy from `lv_fit_t`
 * @param bottom bottom fit policy from `lv_fit_t`
 */
static inline void lv_btn_set_fit4(lv_obj_t * btn, lv_fit_t left, lv_fit_t right, lv_fit_t top,
                                   lv_fit_t bottom)
{
    lv_cont_set_fit4(btn, left, right, top, bottom);
}

/**
 * Set the fit policy horizontally and vertically separately.
 * It tell how to change the button size automatically.
 * @param btn pointer to a button object
 * @param hot horizontal fit policy from `lv_fit_t`
 * @param ver vertical fit policy from `lv_fit_t`
 */
static inline void lv_btn_set_fit2(lv_obj_t * btn, lv_fit_t hor, lv_fit_t ver)
{
    lv_cont_set_fit2(btn, hor, ver);
}

/**
 * Set the fit policy in all 4 direction at once.
 * It tell how to change the button size automatically.
 * @param btn pointer to a button object
 * @param fit fit policy from `lv_fit_t`
 */
static inline void lv_btn_set_fit(lv_obj_t * cont, lv_fit_t fit)
{
    lv_cont_set_fit(cont, fit);
}

/**
 * Set time of the ink effect (draw a circle on click to animate in the new state)
 * @param btn pointer to a button object
 * @param time the time of the ink animation
 */
void lv_btn_set_ink_in_time(lv_obj_t * btn, uint16_t time);

/**
 * Set the wait time before the ink disappears
 * @param btn pointer to a button object
 * @param time the time of the ink animation
 */
void lv_btn_set_ink_wait_time(lv_obj_t * btn, uint16_t time);

/**
 * Set time of the ink out effect (animate to the released state)
 * @param btn pointer to a button object
 * @param time the time of the ink animation
 */
void lv_btn_set_ink_out_time(lv_obj_t * btn, uint16_t time);

/**
 * Set a style of a button.
 * @param btn pointer to button object
 * @param type which style should be set
 * @param style pointer to a style
 *  */
void lv_btn_set_style(lv_obj_t * btn, lv_btn_style_t type, const lv_style_t * style);

/*=====================
 * Getter functions
 *====================*/

/**
 * Get the current state of the button
 * @param btn pointer to a button object
 * @return the state of the button (from lv_btn_state_t enum)
 */
lv_btn_state_t lv_btn_get_state(const lv_obj_t * btn);

/**
 * Get the toggle enable attribute of the button
 * @param btn pointer to a button object
 * @return ture: toggle enabled, false: disabled
 */
bool lv_btn_get_toggle(const lv_obj_t * btn);

/**
 * Get the layout of a button
 * @param btn pointer to button object
 * @return the layout from 'lv_cont_layout_t'
 */
static inline lv_layout_t lv_btn_get_layout(const lv_obj_t * btn)
{
    return lv_cont_get_layout(btn);
}

/**
 * Get the left fit mode
 * @param btn pointer to a button object
 * @return an element of `lv_fit_t`
 */
static inline lv_fit_t lv_btn_get_fit_left(const lv_obj_t * btn)
{
    return lv_cont_get_fit_left(btn);
}

/**
 * Get the right fit mode
 * @param btn pointer to a button object
 * @return an element of `lv_fit_t`
 */
static inline lv_fit_t lv_btn_get_fit_right(const lv_obj_t * btn)
{
    return lv_cont_get_fit_right(btn);
}

/**
 * Get the top fit mode
 * @param btn pointer to a button object
 * @return an element of `lv_fit_t`
 */
static inline lv_fit_t lv_btn_get_fit_top(const lv_obj_t * btn)
{
    return lv_cont_get_fit_top(btn);
}

/**
 * Get the bottom fit mode
 * @param btn pointer to a button object
 * @return an element of `lv_fit_t`
 */
static inline lv_fit_t lv_btn_get_fit_bottom(const lv_obj_t * btn)
{
    return lv_cont_get_fit_bottom(btn);
}

/**
 * Get time of the ink in effect (draw a circle on click to animate in the new state)
 * @param btn pointer to a button object
 * @return the time of the ink animation
 */
uint16_t lv_btn_get_ink_in_time(const lv_obj_t * btn);

/**
 * Get the wait time before the ink disappears
 * @param btn pointer to a button object
 * @return the time of the ink animation
 */
uint16_t lv_btn_get_ink_wait_time(const lv_obj_t * btn);

/**
 * Get time of the ink out effect (animate to the releases state)
 * @param btn pointer to a button object
 * @return the time of the ink animation
 */
uint16_t lv_btn_get_ink_out_time(const lv_obj_t * btn);

/**
 * Get style of a button.
 * @param btn pointer to button object
 * @param type which style should be get
 * @return style pointer to the style
 *  */
const lv_style_t * lv_btn_get_style(const lv_obj_t * btn, lv_btn_style_t type);

/**********************
 *      MACROS
 **********************/

#endif /*LV_USE_BUTTON*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_BTN_H*/
