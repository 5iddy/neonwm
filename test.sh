#!/bin/sh

Xephyr -nolisten local -nolisten tcp -ac -reset -terminate -br +iglx -resizeable -fullscreen -s off :1 >/dev/null 2>&1 &

sleep 1
# DISPLAY=:1 feh --bg-fill "/home/noodles/Pictures/wallpapers/alena-aenami-witcher-1k.jpg" &

# DISPLAY=:1 conky -c ~/.config/conky/dwm.conf | DISPLAY=:1 dwm-status &

#while true; do
  #DISPLAY=:1 $HOME/.local/bin/dwm
DISPLAY=:1 ./dwm
#done

