/* See LICENSE file for copyright and license details. */

#ifndef __DWM_CONFIG_H__
#define __DWM_CONFIG_H__
/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const double defaultopacity  = 0.8;
static const double fullopacity     = 1.0;
static const char *fonts[]          = { "mononoki Nerd Font:pixelsize=18:style=regular:antialias=true:autohint=true",
    "FontAwesome:pixelsize=18:antialias=true:autohint=true", 
    "Noto Sans Telugu UI:pixelsize=18:antialias=true:autohint=true",
                                      };
static const char dmenufont[]       = "mononoki Nerd Font:pixelsize=18:antialias=true:autohint=true";
static const char col_gray1[]       = "#24222F";
static const char col_gray2[]       = "#2d2b3a";
static const char col_gray3[]       = "#8E87C1";
static const char col_gray4[]       = "#A49ED6";
static const char col_cyan[]        = "#26D2F6";
static const char col_green[]       = "#35DD9D";
static const char col_red[]         = "#ff4892";
static const char col_yellow[]      = "#FFBE20";
static const char col_blue[]        = "#63BCFF";
static const char col_magenta[]     = "#FB49C6";
static const char col_white[]       = "#EAEAEA";
static const char col_cyan2[]       = "#2bfbfb";
static const char col_yellow2[]     = "#EBEC5E";
static const char col_green2[]      = "#89EC4B";

static const unsigned int baralpha = 0xd0;
static const unsigned int borderalpha = OPAQUE;

static const char *monocle_symbols[10] = { "","","","","","","","","","" };

static const char *colors[][3]      = {
	//               fg         bg         border   
	[SchemeNorm] = { col_gray4, col_gray2, col_gray3 },
	[SchemeSel]  = { col_magenta, col_gray1, col_cyan },
};

static const unsigned int alphas[][3]      = {
	//               fg      bg        border     
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "" };
// uncomment the below line for english tags 
static const char *tagsalt[] = { "", "", "", "", "", "", "", "", "" }; 
// uncomment the line below for telugu tags
// static const char *tagsalt[] = { "౧", "౨", "౩", "౪", "౫", "౬", "౭", "౮", "౯" }; // for telugu numbers, requires noto-fonts to work
static const int momentaryalttags = 0; /* 1 means alttags will show only when key is held down*/

static const char *tagsel[][2] = {
	{ col_red,      col_gray1 },
	{ col_yellow,   col_gray1 },
	{ col_green,    col_gray1 },
	{ col_blue,     col_gray1 },
	{ col_magenta,  col_gray1 },
	{ col_white,    col_gray1 },
	{ col_cyan2,    col_gray1 },
	{ col_yellow2,  col_gray1 },
	{ col_green2,   col_gray1 },
};

static const unsigned int tagalpha[] = { OPAQUE, baralpha };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
  /* class      instance    title       tags mask     isfloating	 opacity   	   monitor */
	{ "Gimp",     NULL,       NULL,         0,          1,         fullopacity,		   -1  },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,         fullopacity,		   -1  },
	{ "St",	      NULL,       NULL,         0,          0,         fullopacity,      -1  },
	{ "Chromium", NULL,       NULL,         0,          0,         fullopacity,      -1  },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int   nmaster     = 2;    /* number of clients in master area */
static const int   resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int   lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

#include "grid.c"
#include "horizgrid.c"
#include "nmaster.c"
static const Layout layouts[] = {
	// symbol   arrange function
	{ "",      tile      }, // [0] tile isdefault
	{ "",      monocle   }, // [1]
  { "",      grid      }, // [2]
  { "",      horizgrid }, // [3]
	{ "",      NULL      }, // [4] no layout function means floating behavior
  { "TTT",    bstack    }, // [5]
  { "-|=",    ntile     }, // [6]
	{ "-|-",    nbstack   }, // [7]
  { "|||",    ncol      }, // [8]
  { NULL,     NULL      }, 
};

/* key definitions */
#define ALTKEY Mod1Mask
#define SUPERKEY Mod4Mask
#define MODKEY ALTKEY
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define SPAWNSH(cmd) { "/bin/sh", "-c", cmd, NULL }
#define TERM(title, cmd) { .v = (const char*[]){ "st",  "-T", title, "-e", cmd, NULL } }
#define SPAWN(title, cmd) { "st",  "-T", title, "-e", cmd, NULL }
#define ROFI(cmd) { .v = (const char*[]){ "/home/noodles/.config/rofi/bin/" cmd, NULL  } }

/* launcher commands (They must be NULL terminated) */
static const char *termcmd[]      = {"st", NULL};
static const char *alacrittycmd[] = {"alacritty", NULL};
static const char *chromium[]     = {"chromium", NULL};
static const char *duck[]         = {"surf", "https://duckduckgo.com", NULL};
static const char *yt[]           = {"surf", "https://youtube.com", NULL};
static const char *firefox[]      = {"firefox", NULL};
static const char *nvim[]         = SPAWN("nvim", "nvim");
static const char *ranger[]       = SPAWN("Ranger", "ranger");
static const char *thunar[]       = SPAWNSH("thunar");
static const char *pavucontrol[]  = SPAWNSH("pavucontrol");

static const Launcher launchers[] = {
       /* command       name to display */
	{ duck,         "" },
  { yt,           "" },
  { firefox,      "" },
  { nvim,         "" },
  { chromium,     "" },
  { ranger,       "" },
  { thunar,       "" },
  { pavucontrol,  "" },
};

static const char *const autostart[] = {
  "picom", "--config", "/home/noodles/.config/picom/dwm.conf", NULL,
  "eval", "$(ssh-agent -s)", NULL,
  NULL /* terminate */
};

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };

static Key keys[] = {
	/* modifier                     key             function        argument */
	{ MODKEY,                       XK_p,           spawn,          {.v = dmenucmd }     },
	{ MODKEY|ShiftMask,             XK_Return,      spawn,          {.v = termcmd }      },
	{ MODKEY,                       XK_b,           togglebar,      {0}                  },
	{ MODKEY,                       XK_j,           focusstack,     {.i = +1 }           },
	{ MODKEY,                       XK_k,           focusstack,     {.i = -1 }           },
	{ MODKEY,                       XK_i,           incnmaster,     {.i = +1 }           },
	{ MODKEY,                       XK_d,           incnmaster,     {.i = -1 }           },
  { MODKEY,                       XK_x,           setnmaster,     {.i = 2 }            },
	{ MODKEY,                       XK_h,           setmfact,       {.f = -0.05}         },
	{ MODKEY,                       XK_l,           setmfact,       {.f = +0.05}         },
	{ MODKEY,                       XK_Return,      zoom,           {0}                  },
	{ MODKEY,                       XK_Tab,         focusstack,     {.i = +1}            },
	{ MODKEY|ShiftMask,             XK_Tab,         focusstack,     {.i = -1}            },
	{ MODKEY|ShiftMask,             XK_c,           killclient,     {0}                  },
  // Setting layout shortcuts
	{ MODKEY,                       XK_t,           setlayout,      {.v = &layouts[0]}   }, // tile
	{ MODKEY,                       XK_m,           setlayout,      {.v = &layouts[1]}   }, // monocle
  { MODKEY,                       XK_g,           setlayout,      {.v = &layouts[2]}   }, // grid
  { MODKEY|ShiftMask,             XK_g,           setlayout,      {.v = &layouts[3]}   }, // horizgrid
	{ MODKEY,                       XK_f,           setlayout,      {.v = &layouts[4]}   }, // floats
  { MODKEY,                       XK_u,           setlayout,      {.v = &layouts[5]}   }, // bstack
  { MODKEY|ControlMask,		        XK_comma,       cyclelayout,    {.i = -1 }           },
	{ MODKEY|ControlMask,           XK_period,      cyclelayout,    {.i = +1 }           },
	{ MODKEY,                       XK_space,       setlayout,      {0}                  },
	{ MODKEY|ShiftMask,             XK_space,       togglefloating, {0}                  },
	{ MODKEY,                       XK_0,           view,           {.ui = ~0 }          },
	{ MODKEY|ShiftMask,             XK_0,           tag,            {.ui = ~0 }          },
	{ MODKEY,                       XK_comma,       focusmon,       {.i = -1 }           },
	{ MODKEY,                       XK_period,      focusmon,       {.i = +1 }           },
	{ MODKEY|ShiftMask,             XK_comma,       tagmon,         {.i = -1 }           },
	{ MODKEY|ShiftMask,             XK_period,      tagmon,         {.i = +1 }           },
  { MODKEY|ShiftMask,		          XK_KP_Add,      changeopacity,	{.f = +0.1}          },
	{ MODKEY|ShiftMask,		          XK_KP_Subtract, changeopacity,  {.f = -0.1}          },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,           quit,      {0}                       },
  { SUPERKEY,                     XK_space,       spawn,     ROFI("launcher_misc")     },
  { SUPERKEY,                     XK_r,           spawn,     ROFI("launcher_colorful") },
  { SUPERKEY,                     XK_q,           spawn,     ROFI("menu_powermenu")    },
  { SUPERKEY,                     XK_a,           spawn,     {.v = alacrittycmd}       },
  { SUPERKEY,                     XK_c,           spawn,     {.v = chromium }          },
  { SUPERKEY,                     XK_v,           spawn,     TERM("neovim", "nvim")    },
  { MODKEY,                       XK_n,      togglealttag,   {0}                       },
  { MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" }    },
	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" }   },
	{ MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" }    },
	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" }   },
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" }    },
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" }   },
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" }    },
	{ MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" }   },
	{ MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"}                },
	{ MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"}                },
	{ MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"}                },
	{ MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"}                },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge, {.v = "T"}                },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge, {.v = "B"}                },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge, {.v = "L"}                },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge, {.v = "R"}                },
  { SUPERKEY,                     XK_Left,   viewtoleft,     {0}                       },
	{ SUPERKEY,                     XK_Right,  viewtoright,    {0}                       },
	{ SUPERKEY|ShiftMask,           XK_Left,   tagtoleft,      {0}                       },
	{ SUPERKEY|ShiftMask,           XK_Right,  tagtoright,     {0}                       },
  { MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1}                       },
  { SUPERKEY,                     XK_e,      spawn,          SHCMD("thunar")           },
  { SUPERKEY,                     XK_t,      spawn,          SHCMD("st")               },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        cyclelayout,    {.i = 1 } },
	{ ClkLtSymbol,          0,              Button3,        cyclelayout,    {.i = -1 } },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

#endif // __DWM_CONFIG_H__
