
/*
 ==========================================================================

 Copyright (C) 2018 Giancarlo Zollino
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

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "gtest/gtest.h"

#include "Config.hpp"
#include "ConfigTestFileManager.hpp"
#include "RTA_EVT2b_DB.hpp"

using std::cout;
using std::endl;
using std::vector;
using std::shared_ptr;
using std::make_shared;


vector < map <string, string> > randomEventsGenerator(int size);


TEST(RTA_DL_DB, streamingSingleThreadMysqlTest) {

  Mutex* mux = Mutex::getIstance();
  Config * myConf;
  myConf = Config::getIstance();

  map < string, vector < map < string, string > > > section;
  vector < map < string, string > > entry;
  map < string, string>  kv;

  kv["modelname"]= myConf->file["General"]["modelname"].getString();
  kv["mjdref"]= myConf->file["General"]["modelname"].getString();
  kv["debug"]= myConf->file["General"]["debug"].getString();
  kv["batchsize"]= "1";
  kv["numberofthreads"]= myConf->file["General"]["numberofthreads"].getString();
  entry.push_back(kv);
  section["General"] = entry;

  myConf->deleteInstance();
  ConfigTestFileManager::writeConfigFile(section);
  myConf->deleteInstance();

  auto rtaTestDb = make_shared<RTA_EVT2b_DB>("mysql");

  vector < map < string, string > > events = randomEventsGenerator(1);

  rtaTestDb->start();

  for(vector < map < string, string > >::iterator it = events.begin(); it!=events.end(); ++it ) {

    map < string, string > currentEvent = *it;

    EXPECT_TRUE( rtaTestDb->insertEvent(
                                        currentEvent["gps_st"] ,
                                        currentEvent["time_ut"] ,
                                        currentEvent["evt_time_s"] ,
                                        currentEvent["evt_time_ns"] ,
                                        currentEvent["zd"] ,
                                        currentEvent["az"] ,
                                        currentEvent["src_pos_x"] ,
                                        currentEvent["src_pos_y"] ,
                                        currentEvent["img_stvalid"] ,
                                        currentEvent["img_stxdir"] ,
                                        currentEvent["img_stydir"] ,
                                        currentEvent["img_stxcore"] ,
                                        currentEvent["img_stycore"] ,
                                        currentEvent["img_stmaxh"] ,
                                        currentEvent["img_min_dir"] ,
                                        currentEvent["img_min_core"] ,
                                        currentEvent["img_min_maxh"] ,
                                        currentEvent["st_imp_par"] ,
                                        currentEvent["g_gammaness"] ,
                                        currentEvent["g_est_en"] ,
                                        currentEvent["xdisp"] ,
                                        currentEvent["ydisp"] ,
                                        currentEvent["ra"] ,
                                        currentEvent["dec"] ,
                                        currentEvent["evtnum"] ,
                                        currentEvent["ntrigtel"] ,
                                        currentEvent["n_used_tel"] ,
                                        currentEvent["n_used_tel_reco"] ,
                                        currentEvent["observationid"] ,
                                        currentEvent["datarepositoryid"]
                                       ) );
  }

  rtaTestDb->waitAndClose();

  myConf->deleteInstance();
  ConfigTestFileManager::writeConfigFile();

}


vector < map <string, string> > randomEventsGenerator(int size){

  map <string, string> args;

  vector < map <string, string> > events;

  /*  CREAZIONE EVENTI RANDOM  */
  for(int i=0; i<size; i++){
    args["gps_st"] =to_string(rand());
    args["time_ut"] =to_string(rand());
    args["evt_time_s"] =to_string(rand());
    args["evt_time_ns"] =to_string(rand());
    args["zd"] =to_string(rand());
    args["az"] =to_string(rand());
    args["src_pos_x"] =to_string(rand());
    args["src_pos_y"] =to_string(rand());
    args["img_stvalid"] =to_string(rand());
    args["img_stxdir"] =to_string(rand());
    args["img_stydir"] =to_string(rand());
    args["img_stxcore"] =to_string(rand());
    args["img_stycore"] =to_string(rand());
    args["img_stmaxh"] =to_string(rand());
    args["img_min_dir"] =to_string(rand());
    args["img_min_core"] =to_string(rand());
    args["img_min_maxh"] =to_string(rand());
    args["st_imp_par"] =to_string(rand());
    args["g_gammaness"] =to_string(rand());
    args["g_est_en"] =to_string(rand());
    args["xdisp"] =to_string(rand());
    args["ydisp"] =to_string(rand());
    args["ra"] =to_string(rand());
    args["dec"] =to_string(rand());
    args["evtnum"] =to_string(rand());
    args["ntrigtel"] =to_string(rand());
    args["n_used_tel"] =to_string(rand());
    args["n_used_tel_reco"] =to_string(rand());
    args["observationid"] =to_string(rand());
    args["datarepositoryid"] =to_string(rand());


    events.push_back(args);

  }

  return events;

}



int main(int argc, char **argv) {

  ::testing::InitGoogleTest(&argc, argv);



  char * val = getenv( "RTALIBCONFIG" );

  if (val != NULL) {
    return RUN_ALL_TESTS();
  }
  else{
    cout << "Please define the RTACONFIGFILE environment variable." << endl;
    //export RTACONFIGFILE=/home/cta/Baroncelli_development/ASTRI_DL2/RTAlib-ASTRI/CxxRTAlib/TestEnvironment/src_cpp
  }



}
