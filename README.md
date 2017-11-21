# Fork info

This is a humble fork in order to add specific funcionality to ClickHouse/MySQL connections into Yandex' original code by extended **client** library into **proxy** one. So do not try to merge back without a careful study on side-effects:

	git clone --recursive https://github.com/xue2sheng/ClickHouse.git 

A way to get info on server build options could be:

	clickhouse-proxy --query="select * from system.build_options"

Or using HTTP protocol:

	echo 'select * from system.build_options' | curl 'http://localhost:8123/' --data-binary @-

For just full version on local client binary:

	 strings /usr/bin/clickhouse-proxy | grep "^ClickHouse 1.1"

## Proxy 

Being just an extension of *client* library, it's expected to get equivalent */etc/clickhouse-proxy* folder and */usr/bin/clickhouse-proxy* symbolic link. Its *config.xml* configuration file will be as well just an extension from *client* one.

# Original info

ClickHouse is an open-source column-oriented database management system that allows generating analytical data reports in real time.

[Read more...](https://clickhouse.yandex/)
