
Debian
====================
This directory contains files used to package mqxd/mqx-qt
for Debian-based Linux systems. If you compile mqxd/mqx-qt yourself, there are some useful files here.

## mqx: URI support ##


mqx-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install mqx-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your mqxqt binary to `/usr/bin`
and the `../../share/pixmaps/mqx128.png` to `/usr/share/pixmaps`

mqx-qt.protocol (KDE)

