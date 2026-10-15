/* See LICENSE file for copyright and license details. */

/* Rama-OI - dwm 6.8
 * Alpine Linux x86 (32-bit)
 * Catppuccin Mocha
 */

#include <X11/XF86keysym.h>

/* Appearance */
static const unsigned int borderpx  = 1;
static const unsigned int snap      = 16;
static const int showbar            = 1;
static const int topbar             = 1;
static const char *fonts[]          = {
    "DejaVu Sans Mono:size=9"
};

static const char col_gray1[]       = "#11111b";
static const char col_gray2[]       = "#313244";
static const char col_gray3[]       = "#a6adc8";
static const char col_gray4[]       = "#cdd6f4";
static const char col_cyan[]        = "#cba6f7";

static const char *colors[][3]      = {
    /*               fg          bg          border   */
    [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
    [SchemeSel]  = { col_gray4, col_gray2, col_cyan  },
};

static const unsigned int gappi    = 8;  /* gap between windows */
static const unsigned int gappo    = 4;  /* gap around the screen edge */

/* Tags / workspaces */
static const char *tags[] = {
    "1", "2", "3", "4",
};

static const Rule rules[] = {
    /* class      instance    title       tags mask     isfloating   monitor */
    { "floating-terminal", NULL, NULL,    0,            1,           -1 },
};

/* Layouts */
static const float mfact          = 0.55;
static const int nmaster           = 1;
static const int resizehints       = 0;
static const int lockfullscreen    = 1;
static const int refreshrate       = 120;

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[T]",      tile },
    // { "><>",      NULL },
    // { "[M]",      monocle },
};

/* Applications */
static char dmenumon[2] = "0";

static const char *dmenucmd[] = {
    "dmenu_run",
    "-i",
    "-m", dmenumon,
    "-nb", "#11111b",
    "-nf", "#a6adc8",
    "-sb", "#cba6f7",
    "-sf", "#11111b",
    NULL
};

static const char *termcmd[] = {
    "st", NULL
};

// static const char *coquicmd[] = {
//     "rama-coqui-launch", NULL
// };

static const char *powercmd[] = {
    "rama-power-menu", NULL
};

/* Key bindings */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY, view,       {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY, toggleview, {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY, tag,        {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY, toggletag,  {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const Key keys[] = {
    /* Modifier       Key          Function        Argument */

    // { MODKEY,         XK_space,    spawn,          {.v = coquicmd} },
    { MODKEY,         XK_z,        spawn,          {.v = termcmd} },
    { MODKEY,         XK_space,        spawn,          {.v = dmenucmd} },
    { MODKEY,         XK_x,        killclient,     {0} },

    { MODKEY|ShiftMask, XK_e,      spawn,          {.v = powercmd} },


    /* Focus windows */
    { MODKEY,         XK_j,        focusstack,     {.i = +1} },
    { MODKEY,         XK_k,        focusstack,     {.i = -1} },
    { MODKEY,         XK_h,        setmfact,       {.f = -0.05} },
    { MODKEY,         XK_l,        setmfact,       {.f = +0.05} },

    /* Layout control */
    // { MODKEY,         XK_f,        setlayout,      {.v = &layouts[1]} },
    // { MODKEY,         XK_m,        setlayout,      {.v = &layouts[2]} },
    // { MODKEY,         XK_Tab,      view,           {0} },
    { MODKEY,         XK_t,        setlayout,      {.v = &layouts[0]} },
    { MODKEY,         XK_b,        togglebar,      {0} },

    /* Master / stack */
    { MODKEY,         XK_i,        incnmaster,     {.i = +1} },
    { MODKEY,         XK_p,        incnmaster,     {.i = -1} },

    /* Restart dwm */
    { MODKEY|ShiftMask, XK_r,      quit,           {1} },

    /* Workspaces */
    TAGKEYS( XK_1, 0 )
    TAGKEYS( XK_2, 1 )
    TAGKEYS( XK_3, 2 )
    TAGKEYS( XK_4, 3 )
};

static const Button buttons[] = {
    /* Click       Event mask      Button          Function        Argument */
    { ClkLtSymbol, 0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol, 0,              Button3,        setlayout,      {.v = &layouts[0]} },
    { ClkWinTitle, 0,              Button2,        zoom,           {0} },
    { ClkClientWin, MODKEY,        Button1,        movemouse,      {0} },
    { ClkClientWin, MODKEY,        Button2,        togglefloating, {0} },
    { ClkClientWin, MODKEY,        Button3,        resizemouse,    {0} },
    { ClkTagBar,   0,              Button1,        view,           {0} },
    { ClkTagBar,   0,              Button3,        toggleview,     {0} },
    { ClkTagBar,   MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,   MODKEY,         Button3,        toggletag,      {0} },
};