# Fork info

This is a humble fork in order to add specific funcionality to ClickHouse/MySQL connections into Yandex' original code so do not try to merge back without a careful study on side-effects:

	git clone --recursive git@github.com:xue2sheng/ClickHouse.git

A way to get info on server build options could be:

	clickhouse-client --query="select * from system.build_options"

Or just full version on local client binary:

	 strings /usr/bin/clickhouse-client | grep "^ClickHouse 1.1"

# Original info

ClickHouse is an open-source column-oriented database management system that allows generating analytical data reports in real time.

[Read more...](https://clickhouse.yandex/)
