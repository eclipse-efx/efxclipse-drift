package org.eclipse.fx.drift.tooling

import javax.xml.parsers.SAXParserFactory
import org.xml.sax.helpers.DefaultHandler
import java.io.File
import org.xml.sax.Attributes
import org.xml.sax.SAXException
import java.util.List

class Command {
	public String type
	public String name
	public List<Param> params = newArrayList
}
class Param {
	public String type
	public String name
}

class MyHandler extends DefaultHandler {
	
	Param curProto = null
	Param curParam = null
	Command curCommand = null
	
	StringBuilder data = new StringBuilder
	
	override characters(char[] ch, int start, int length) throws SAXException {
		data.append(new String(ch, start, length));
	}
	
	override startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
		switch (qName) {
			case "command": {
				curCommand = new Command
			}
			case "param": {
				curParam = new Param
			}
			case "proto": {
				data = new StringBuilder
				curProto = new Param
			}
			case "name": {
				data = new StringBuilder
				if (curProto != null) curProto.type = data.toString
			}
			case "ptype": {
				data = new StringBuilder
			}
		}
		
	}
	
	override endElement(String uri, String localName, String qName) throws SAXException {
		switch (qName) {
			case "command": {
				System.err.println(''' * «curCommand.type» «curCommand.name»(«FOR p : curCommand.params SEPARATOR ", " »«p.type» «p.name»«ENDFOR»)''')
				
				curCommand = null;
				
			}
			case "param": {
				curCommand.params.add(curParam)
				curParam = null
			}
			case "proto": {
				curCommand.name = curProto.name
				curCommand.type = curProto.type
				curProto = null
			}
			case "name": {
				if (curProto != null) curProto.name = data.toString
				if (curParam != null) curParam.name = data.toString
			}	
			case "ptype": {
				//if (curProto != null) curProto.type = data.toString
				if (curParam != null) curParam.type = data.toString
			}
		}
	}
	
}


class GLProcsGenerator {
	
	static def doIt() {
		var factory = SAXParserFactory.newInstance();
		var handler = new MyHandler
		
		var parser = factory.newSAXParser
		
		parser.parse(new File("C:\\Users\\Christoph\\Projects\\drift\\wa2\\org.eclipse.fx.drift.tooling\\gl.xml"), handler);
		
	}
	
	def static void main(String[] args) {
		doIt();
	}
	
}