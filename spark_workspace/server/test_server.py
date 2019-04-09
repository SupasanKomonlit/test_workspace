from lightning import Lightning

from numpy import random

lgn = Lightning( host="http://public.lightning-viz.org/.")

series = random.randn(5 , 50 )

lgn.create_session()
lgn.create_session( "TESTING" )
lgn.line( series )
