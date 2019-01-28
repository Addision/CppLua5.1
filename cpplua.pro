#***************************************************************************
#*   Copyright (C) 2004 by Paolo Capriotti                                 *
#*   p.capriotti@sns.it                                                    *
#*                                                                         *
#*   This program is free software; you can redistribute it and/or modify  *
#*   it under the terms of the GNU General Public License as published by  *
#*   the Free Software Foundation; either version 2 of the License, or     *
#*   (at your option) any later version.                                   *
#*                                                                         *
#*   This program is distributed in the hope that it will be useful,       *
#*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
#*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
#*   GNU General Public License for more details.                          *
#*                                                                         *
#*   You should have received a copy of the GNU General Public License     *
#*   along with this program; if not, write to the                         *
#*   Free Software Foundation, Inc.,                                       *
#*   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
#***************************************************************************/

TEMPLATE = app
INCLUDEPATH += /usr/include/lua50 

# Input
HEADERS += common.h cpplua.h luafunction.h luaobject.h luastate.h luatable.h stackcollectible.h
SOURCES += luafunction.cpp luaobject.cpp luastate.cpp test.cpp luatable.cpp stackcollectible.cpp
CONFIG -= qt
CONFIG += debug
LIBS += -ldl -llua50 -llualib50
