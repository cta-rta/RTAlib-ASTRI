/*
 ==========================================================================

 Copyright (C) 2018 Leonardo Baroncelli

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ==========================================================================
*/

#include "EVT2b.hpp"

EVT2b::EVT2b(
               string gps_st,
               string time_ut,
               string evt_time_s,
               string evt_time_ns,
               string zd,
               string az,
               string src_pos_x,
               string src_pos_y,
               string img_stvalid,
               string img_stxdir,
               string img_stydir,
               string img_stxcore,
               string img_stycore,
               string img_stmaxh,
               string img_min_dir,
               string img_min_core,
               string img_min_maxh,
               string st_imp_par,
               string g_gammaness,
               string g_est_en,
               string xdisp,
               string ydisp,
               string ra,
               string dec,
               string evtnum,
               string ntrigtel,
               string n_used_tel,
               string n_used_tel_reco,
               string observationid,
               string datarepositoryid,
               string status,
               bool last ) : EVTbase(last){

   eventData["gps_st"] = gps_st;
   eventData["time_ut"] = time_ut;
   eventData["evt_time_s"] = evt_time_s;
   eventData["evt_time_ns"] = evt_time_ns;
   eventData["zd"] = zd;
   eventData["az"] = az;
   eventData["src_pos_x"] = src_pos_x;
   eventData["src_pos_y"] = src_pos_y;
   eventData["img_stvalid"] = img_stvalid;
   eventData["img_stxdir"] = img_stxdir;
   eventData["img_stydir"] = img_stydir;
   eventData["img_stxcore"] = img_stxcore;
   eventData["img_stycore"] = img_stycore;
   eventData["img_stmaxh"] = img_stmaxh;
   eventData["img_min_dir"] = img_min_dir;
   eventData["img_min_core"] = img_min_core;
   eventData["img_min_maxh"] = img_min_maxh;
   eventData["st_imp_par"] = st_imp_par;
   eventData["g_gammaness"] = g_gammaness;
   eventData["g_est_en"] = g_est_en;
   eventData["xdisp"] = xdisp;
   eventData["ydisp"] = ydisp;
   eventData["ra"] = ra;
   eventData["dec"] = dec;
   eventData["evtnum"] = evtnum;
   eventData["ntrigtel"] = ntrigtel;
   eventData["n_used_tel"] = n_used_tel;
   eventData["n_used_tel_reco"] = n_used_tel_reco;
   eventData["observationid"] = observationid;
   eventData["datarepositoryid"] = datarepositoryid;

};

map <string,string> & EVT2b::getData() {
  map<string, string>::iterator it;
  for ( it = eventData.begin(); it != eventData.end(); it++ ) {
    if (it->second.compare("nan") == 0 || it->second.compare("-nan") == 0 || it->second.compare("+nan") == 0)
      it->second = "NULL";
  }
  return eventData;
}
