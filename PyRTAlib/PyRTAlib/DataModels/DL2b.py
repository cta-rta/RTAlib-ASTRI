# ==========================================================================
#
# Copyright (C) 2018 INAF - OAS Bologna
# Author: Leonardo Baroncelli <leonardo.baroncelli26@gmail.com>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#
# ==========================================================================
import time
from random import randint, uniform


from .EVTbase import EVTbase
from ..Utils import time_mjd_to_tt


class DL2b(EVTbase):
    def __init__(self, eventidfits, observationid, datarepositoryid):
        super().__init__();

        self.eventidfits = float(eventidfits)
        self.observationid = int(observationid)
        self.datarepositoryid = int(datarepositoryid)


    def getData(self):
        """Return the 'dictionary' representation of the object.
        """
        return vars(self)

    @staticmethod
    def getRandomEvent():
        rndEvent = []
        rndEvent.append(randint(0, 9999999))
        rndEvent.append(randint(0, 9999999))
        rndEvent.append(randint(0, 9999999))

        return rndEvent
