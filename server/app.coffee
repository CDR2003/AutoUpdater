express = require 'express'

app = express()


app.get '/info.json', (req, res) ->
	res.end '{ "result": "ok" }'


app.listen 4000