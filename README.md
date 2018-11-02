# RTAlib-astri

## Installation

### Prerequisities
* A python 3.6 virtual environment

### Procedure
* Download the source code
```bash
cd ~/
git clone https://github.com/cta-rta/RTAlib-ASTRI
git clone https://github.com/rta-pipe/RTAlib
```
* Execute the following commands to create databases, users, tables and configuration files for the RTAlib.
```bash
cp RTAlib-ASTRI/SetupDB/mysql/setup_astri_datalayers_tables.sql RTAlib/SetupDB/mysql/
bash RTAlib/SetupDB/setup_db.sh
```
* Fill in the configuration files fields
* Activate the python virtual environment and execute the following commands to install the python dependencies.
```bash
cd ~/RTAlib/PyRTAlib
python setup.py install
```
## Running the tests
In order to run the unit tests, you have to define the RTACONFIGFILE environment variable that must point the rtalibconfig_testing configuration file.

### RTAlib unit tests
```bash
export RTACONFIGFILE=~/RTAlib/Configs/rtalibconfig_testing
bash RTAlib/PyRTAlib/TestEnvironment/unit_tests/run_unit_tests.sh
```

### RTAlib-ASTRI unit tests
```bash
export RTACONFIGFILE=~/RTAlib/Configs/rtalibconfig_testing
export PYTHONPATH=~/RTAlib/PyRTAlib
cd ~/RTAlib-ASTRI/PyRTAlib/TestEnvironment/unit_tests
python RTA_EVT3_DB_unittest.py -v
```

## Configure the software
You can improve the software event-rate by changing the values of the *batchsize* and *numberofthreads* parameters in the configuration file.
Warning: with numberofthreads > 1, the feature [B] of the RTAlib will be disabled.

## Running the software

### Importing the RTAlib/RTAlib-ASTRI modules
You have to set the path to the RTAlib modules within the PYTHONPATH to make them globally available.
```bash
export PYTHONPATH=~/RTAlib/PyRTAlib:~/RTAlib-ASTRI/PyRTAlib
```
Now you can import modules from the RTAlib and RTAlib-ASTRI libraries inside your code.

### Example

Import the EVT3 interface to stream EVT3 into RTAlib database
```python
from astri_PyRTAlib.RTAInterface import RTA_EVT3_DB
```

Instantiate an object and choose the database (mysql, redis)
```python
rta_evt3_db = RTA_EVT3_DB('mysql')
```

Use the following method to stream the data
```python
rta_evt3_db.insertEvent( evt2_data.evtnum[i], evt2_data.time[i], evt2_data.ra[i], ..)
```

Close the connection
```python
rta_evt3_db.waitAndClose()
```
