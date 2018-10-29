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

from .RTA_DL_DB import RTA_DL_DB
from ..DataModels import DL2b


class RTA_DL2b_DB(RTA_DL_DB):

    def __init__(self, database, configFilePath = '', pure_multithreading = False):
        super().__init__(database, configFilePath, pure_multithreading)

        # Pipeline Database Updater
        if not self.pure_multithreading and self.config.get('MySqlPipelineDatabase', 'active', 'bool'):
            self.mysqlDbConnector = self.getMySqlConnector(configFilePath, 'MySqlPipelineDatabase')
            if self.mysqlDbConnector.connect():
                print('[RTA_DL2b_DB] Pipeline updater activated.')
            else:
                print('[RTA_DL2b_DB] Cannot connect.')


    def insertEvent(self, eventidfits, observationid, datarepositoryid, status):
        evt2b = DL2b(eventidfits, observationid, datarepositoryid, status)
        committed = super()._insertEvent(evt2b)


    def getRandomEvent(self):
        return DL2b.getRandomEvent()
