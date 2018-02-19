# MarketMaker Command-Line Interface

This application is a CLI front-end to `marketmaker` API (barterDEX).
It builds a JSON requests based on given arguments and display the results returned by the `marketmaker` (MM) back-end.

## How to build

The build system is based on CMake 3.2+. Follow these steps to build the application:

```console
$ mkdir build
$ cd build
$ cmake ..
$ make
```

## Usage

Two ancillary functionalities were also implemented: cached authentication and API refresh.

### Cached Authentication

To avoid the input of user credentials on every invocation, a pseudo-method name `_config` shall be used in order to 
store this information on a local file (`$HOME/.mmcli.config`).

Example:

```console
$ ./marketmaker-cli _config http://127.0.0.1:7783 \
1d8b27b21efabcd96571cd56f91a40fb9aa4cc623d273c63bf9223dc6f8cd81f
```

### Duped API

Instead of duplicating and hard-coding the definition of more than 50 API calls, this application *learns* the MM API 
from the response given for the `help` method and caches these definitions on an external file (`$HOME/.mmcli.api`).
To force refreshing this information, one can use the `_refresh` pseudo-method explicitly:

```console
$ ./marketmaker-cli _refresh
```

### Getting API Help

To see the list of available methods and their parameters you can use:
```console
$ ./marketmaker-cli
Syntax: ./marketmaker-cli [_config URL USERPASS | _refresh | method params*]

Method                Parameters
====================  =============================================
autoprice ........... base,rel,fixed,minprice,maxprice,margin,refbase,refrel,factor,offset
balance ............. coin,address
balances ............ address
bot_buy ............. base,rel,maxprice,relvolume
bot_list ............ 
bot_pause ........... botid
bot_sell ............ base,rel,minprice,basevolume
bot_settings ........ botid,newprice,newvolume
bot_status .......... botid
bot_statuslist ...... 
bot_stop ............ botid
buy ................. base,rel,price,relvolume,timeout,duration,nonce
calcaddress ......... passphrase
disable ............. coin
dividends ........... coin,height
electrum ............ coin,ipaddr,port
enable .............. coin
fundvalue ........... address,holdings,divisor
getcoin ............. coin
getcoins ............ 
getmyprice .......... base,rel
getpeers ............ 
getprice ............ base,rel
getprices ........... 
getrawtransaction ... coin,txid
goal ................ coin,val
instantdex_claim .... 
instantdex_deposit .. weeks,amount,broadcast
inventory ........... coin,reset,passphrase
jpg ................. srcfile,destfile,power2,password,data,required,ind
lastnonce ........... 
listunspent ......... coin,address
myprice ............. base,rel
notarizations ....... coin
notarizations ....... coin
orderbook ........... base,rel,duration
passphrase .......... passphrase,gui,netid,seednode
portfolio ........... 
pricearray .......... base,rel,starttime,endtime,timescale
recentswaps ......... limit
secretaddresses ..... prefix,passphrase,num,pubtype,taddr
sell ................ base,rel,price,basevolume,timeout,duration,nonce
sendrawtransaction .. coin,signedtx
setconfirms ......... coin,numconfirms,maxconfirms
setprice ............ base,rel,price,broadcast
snapshot ............ coin,height
snapshot_balance .... coin,height,addresses
statsdisp ........... starttime,endtime,gui,pubkey,base,rel
stop ................ 
swapstatus .......... base,rel,limit
swapstatus .......... coin,limit
swapstatus .......... pending
swapstatus .......... requestid,quoteid,pending
ticker .............. base,rel
tradesarray ......... base,rel,starttime,endtime,timescale
trust ............... pubkey,trust
withdraw ............ coin,outputs
```

## Unit Tests

The Unit Tests were implemented in C++ using the Google Test Framework (GTF), and their sources are located at 
`$PROJECT_DIR/src/test`. The build system automatically downloads and builds the required GTF.

To run the Unit Tests, just run the following command under the `build` directory:

```console
$ make && ./tests
```