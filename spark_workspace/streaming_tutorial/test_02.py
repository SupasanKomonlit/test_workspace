# FILE          : test_02.py
# AUTHOR        : Supasan Komonliy
# CREATE ON     : 2019, APRIL 9

# reference : https://spark.apache.org/docs/latest/streaming-programming-guide.html
from __future__ import print_function

import sys

from pyspark import SparkContext
from pyspark.streaming import StreamingContext

import pprint

if __name__=="__main__":
    sc = SparkContext( appName="TestSparkSteaming" )
    sc.setLogLevel("OFF") # reference https://spark.apache.org/docs/2.3.0/api/python/pyspark.html#pyspark.SparkContext
    ssc = StreamingContext( sc , 1 ) 
    # Create a local StreamingContext with 2 working thread and batch interval of 1 second
    
    # Create a DStream that will connect to hostname:port example localhost:9999
    lines = ssc.socketTextStream( "localhost" , 9999 )

    words = lines.flatMap( lambda line : line.split(" ") )
    pairs = words.map( lambda word : ( word , 1 ) )
    wordCounts = pairs.reduceByKey( lambda x , y : x + y )

    words.pprint()
    wordCounts.pprint()

    ssc.start()
    ssc.awaitTermination()

# reference 
#   https://github.com/apache/spark/blob/v2.4.1/examples/src/main/python/streaming/network_wordcount.py
# To run this on your local machine, you need to first run a Netcat server
