package org.eclipse.fx.drift.tooling

import javax.xml.parsers.SAXParserFactory
import org.xml.sax.helpers.DefaultHandler
import java.io.File
import org.xml.sax.Attributes
import org.xml.sax.SAXException
import java.util.List
import java.util.Map
import java.util.ArrayList
import java.nio.file.Files
import java.nio.file.OpenOption
import java.nio.file.StandardOpenOption
import java.nio.file.Paths
import java.util.HashSet
 
class Command {
	public String type
	public String name
	public List<Param> params = newArrayList
}
class Param {
	public String type
	public String name
}


class CommandsHandler extends DefaultHandler {
	
	public Map<String, Command> commands = newHashMap
	
	Param curProto = null
	Param curParam = null
	Command curCommand = null
	
	boolean inCommands = false;
	
	StringBuilder data = new StringBuilder
	
	override characters(char[] ch, int start, int length) throws SAXException {
		data.append(new String(ch, start, length));
	}
	
	override startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
		switch (qName) {
			case "commands" : {
				inCommands = true
			}
			case "command": {
				if (inCommands) curCommand = new Command
			}
			case "param": {
				curParam = new Param
				data = new StringBuilder
			}
			case "proto": {
				data = new StringBuilder
				curProto = new Param
			}
			case "name": {
				if (curProto != null) curProto.type = data.toString.trim()
				if (curParam != null) curParam.type = data.toString.trim()
				data = new StringBuilder
			}
			case "ptype": {
				data = new StringBuilder
			}
		}
		
	}
	
	override endElement(String uri, String localName, String qName) throws SAXException {
		switch (qName) {
			case "commands": {
				inCommands = false
			}
			case "command": {
				if (inCommands) {
					var o = commands.put(curCommand.name, curCommand)
					System.err.println(''' * «curCommand.type» «curCommand.name»(«FOR p : curCommand.params SEPARATOR ", " »«p.type» «p.name»«ENDFOR»)''')
					curCommand = null;
				}
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

class Feature {
	public String api
	public String name
	public String number
	
	public List<Require> requires = newArrayList
	public List<Remove> removes = newArrayList
}
class Require {
	public String comment
	public List<String> types = newArrayList
	public List<String> enums = newArrayList
	public List<String> commands = newArrayList
}

class Remove {
	public String profile
	public String comment
	public List<String> types = newArrayList
	public List<String> enums = newArrayList
	public List<String> commands = newArrayList
}

class Collected {
	public List<String> types = newArrayList
	public List<String> enums = newArrayList
	public List<String> commands = newArrayList
}

class Enum {
	public String name
	public String value
}

class EnumHandler extends DefaultHandler {
	public Map<String, Enum> enums = newHashMap
	boolean inEnums
	Enum curEnum
	override startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
		switch (qName) {
			case "enums" : {
				inEnums = true
			}
			case "enum": {
				if (inEnums) {
					curEnum = new Enum
					curEnum.name = attributes.getValue("name")
					curEnum.value = attributes.getValue("value")
				}
			}
		}
	}
	
	override endElement(String uri, String localName, String qName) throws SAXException {
		switch (qName) {
			case "enums": {
				inEnums = false
			}
			case "enum":
				if (inEnums){
					enums.put(curEnum.name, curEnum)
					curEnum = null
				}
		}
	}
	
}

class FeatureHandler extends DefaultHandler {
	
	public List<Feature> features = newArrayList
	
	
	Feature curFeature = null
	Require curRequire = null
	Remove curRemove = null;
	
	override startElement(String uri, String localName, String qName, Attributes attributes) throws SAXException {
		switch (qName) {
			case "feature": {
				curFeature = new Feature;
				curFeature.api = attributes.getValue("api");
				curFeature.name = attributes.getValue("name");
				curFeature.number = attributes.getValue("number");
			}
			case "require": {
				if (curFeature !== null) {
					curRequire = new Require
					curRequire.comment = attributes.getValue("comment")
				}
				
			}
			case "remove": {
				curRemove = new Remove
				curRemove.profile = attributes.getValue("profile")
				curRemove.comment = attributes.getValue("comment")
			}
			case "type": {
				if (curRequire !== null) {
					curRequire.types.add(attributes.getValue("name"))
				}
				else if (curRemove !== null) {
					curRemove.types.add(attributes.getValue("name"))
				}
			}
			case "enum": {
				if (curRequire !== null) {
					curRequire.enums.add(attributes.getValue("name"))
				}
				else if (curRemove !== null) {
					curRemove.enums.add(attributes.getValue("name"))
				}
			}
			case "command": {
				if (curRequire !== null) {
					curRequire.commands.add(attributes.getValue("name"))
				}
				else if (curRemove !== null) {
					curRemove.commands.add(attributes.getValue("name"))
				}
			}
		}
	}
	
	override endElement(String uri, String localName, String qName) throws SAXException {
		switch (qName) {
			case "feature": {
				features.add(curFeature);
				curFeature = null;
			}
			case "require": {
				if (curFeature !== null) {
					curFeature.requires.add(curRequire);
					curRequire = null
				}
			}
			case "remove": {
				curFeature.removes.add(curRemove)
				curRemove = null
			}
		}
	}
	
}


class CPPGenerator {
	static def getClassPackage(String javaClass) {
		var parts = javaClass.split("[.]");
		var parts2 = parts.subList(0, parts.length-1);
		return parts2.join(".");
	}
	static def getClassName(String javaClass) {
		var parts = javaClass.split("[.]");
		return parts.get(parts.length-1);
	}
	static def getJNIMethodNamespace(String javaClass) {
		return javaClass.replaceAll("[.]", "_");
	}
	
	def generateJavaParameterList(Command c) '''(«FOR p : c.params SEPARATOR ", "»«p.type» «p.name»«ENDFOR»)'''
	
	def generateJniJava(String javaClass, List<Enum> enums, List<Command> commands) '''
	package «javaClass.getClassPackage»;
	
	public final class «javaClass.getClassName» {
		
		«FOR e : enums»
			public static final int «e.name» = «e.value»;
		«ENDFOR»
		
		«FOR c : commands»
			public static native «c.type» «c.name»«c.generateParameterList»;
		«ENDFOR»
	}
	
	'''
	
	
	
	def generateJniCPP(String javaClass, List<Enum> enums, List<Command> commands) '''
	#include <jni.h>
	
	extern "C" {
		
		«FOR c : commands»
			extern "C" JNIEXPORT «c.jniCType» JNICALL Java_«javaClass.JNIMethodNamespace»_«c.name»«c.jniCParameterList» {
				driftgl::«c.name»«c.jniCParameterCallList»;
			}
				
			public static native «c.type» «c.name»«c.generateParameterList»;
		«ENDFOR»
		
	}
	
	'''
	
	static def getJniCType(Command c) {
		switch (c.type) {
			default: return "/*TODO*/ " +c.type
		}
	}
	
	static def getJniCParameterList(Command c) {
		return "(" + ")";
	}
	static def getJniCParameterCallList(Command c) {
		return "(" + ")";
	}
	
	def generateHeader(List<Enum> enums, List<Command> commands) '''
	
	#ifndef GL_CONTEXT_GEN_H_
	#define GL_CONTEXT_GEN_H_
	
	#include <cstdint>
	#include <stddef.h>
	
	namespace driftgl {
		typedef void GLvoid;
		typedef unsigned int GLenum;
		typedef float GLfloat;
		typedef int GLint;
		typedef int GLsizei;
		typedef unsigned int GLbitfield;
		typedef double GLdouble;
		typedef unsigned int GLuint;
		typedef unsigned char GLboolean;
		typedef unsigned char GLubyte;
		typedef char GLchar;
		typedef short GLshort;
		typedef signed char GLbyte;
		typedef unsigned short GLushort;
		
		
		typedef unsigned short GLhalf;
		typedef struct __GLsync *GLsync;
		typedef uint64_t GLuint64;
		typedef int64_t GLint64;
		typedef ptrdiff_t GLsizeiptr;
		typedef ptrdiff_t GLintptr;
		
		typedef void (*GLDEBUGPROC)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
		
		
		«FOR e : enums»
			extern unsigned int «e.name»;
		«ENDFOR»
		
		«FOR c : commands»
			«c.generateAPICall»
		«ENDFOR»
		
		namespace procs {
			typedef void* (LookupFunctionPointer(const char* functionName));
			void Initialize(LookupFunctionPointer lookupFunctionPointer);
		}
	}
	
	#endif
	'''
	def generateSource(List<Enum> enums, List<Command> commands) '''
	
		#include "DriftGL_gen.h"
	
		namespace driftgl {
					
			«FOR e : enums»
				unsigned int «e.name» = «e.value»;
			«ENDFOR»
			
			namespace procs {
				«FOR c : commands»
					«c.generateProcTypedef»
				«ENDFOR»
				
				«FOR c : commands»
					«c.toProcDef» «c.toProcVar»;
				«ENDFOR»
				
				void Initialize(LookupFunctionPointer lookupFunctionPointer) {
					«FOR c : commands»
						«c.toProcVar» = («c.toProcDef»)lookupFunctionPointer("«c.name»");
					«ENDFOR»
				}
				
			}
			
			«FOR c : commands»
				«c.type» «c.name»«c.generateParameterList» {
					return procs::«c.toProcVar»«c.generateParameterCall»;
				}
			«ENDFOR»
		}
	'''
	
	static def toProcVar(Command c) '''pfn�c.name.toFirstUpper�'''
	static def toProcDef(Command c) '''PFN�c.name.toUpperCase�'''
	
	def generateAPICall(Command c) '''
	«c.type» «c.name»«c.generateParameterList»;
	'''
	
	def generateParameterList(Command c) '''(«FOR p : c.params SEPARATOR ", "»«p.type» «p.name»«ENDFOR»)'''
	def generateParameterCall(Command c) '''(«FOR p : c.params SEPARATOR ", "»«p.name»«ENDFOR»)'''
	def generateProcTypedef(Command c) '''
	typedef «c.type» (* «c.toProcDef») «c.generateParameterList»;
	'''
}


class GLProcsGenerator {
	
	static def generateGLProcs(String path, String outH, String outCPP, String jniJava, String jniCPP) {
		var factory = SAXParserFactory.newInstance();
		val commands = new CommandsHandler
		
		var parser = factory.newSAXParser
		
		//var path = "C:\\Users\\Christoph\\Projects\\drift\\git\\drift\\org.eclipse.fx.drift.tooling\\gl.xml";
		
		var features = new FeatureHandler
		parser.parse(new File(path), features)
		
		println(features.features.map[f|f.show()])
		
		println()
		println(" ========================================================================= ")
		println()
		var core = collectGLCore(features.features)
		println(core.show())
		
		
	
		val enums = new EnumHandler
		
		parser.parse(new File(path), enums)
		
		parser.parse(new File(path), commands)
		
		
		println("need " + core.enums.size + " of " + enums.enums.size + " enums")
		println("need " + core.commands.size + " of " + commands.commands.size + " commands")
		
		
		
		var e = core.enums.map[name| {
			if (!enums.enums.containsKey(name)) {
				System.err.println("MISSING " + name);
			}
			return enums.enums.get(name)
			}]
		
		var eu = new ArrayList<Enum>
		var es = new HashSet<String>
		
		for(en : e) {
			if (!es.contains(en.name)) {
				es.add(en.name);
				eu.add(en);
			}
		}	
		
		var c = core.commands.map[name|{
			commands.commands.get(name)}
			]
		
		var cu = new ArrayList<Command>
		var cs = new HashSet<String>
		
		for(cn : c) {
			if (!cs.contains(cn.name)) {
				cs.add(cn.name);
				cu.add(cn);
			}
		}	
		
		val g = new CPPGenerator;
		
		//println(g.generateHeader(e, c))
		
		//var outH = '''C:\Users\Christoph\Projects\drift\git\drift\native\lib\DriftGL\include\DriftGL_gen.h'''
		//var outCPP = '''C:\Users\Christoph\Projects\drift\git\drift\native\lib\DriftGL\src\DriftGL_gen.cpp'''
		
		Files.write(Paths.get(outH), g.generateHeader(eu, cu).toString.bytes, StandardOpenOption.TRUNCATE_EXISTING, StandardOpenOption.CREATE)
		Files.write(Paths.get(outCPP), g.generateSource(eu, cu).toString.bytes, StandardOpenOption.TRUNCATE_EXISTING, StandardOpenOption.CREATE)
		
		var cls = "org.eclipse.fx.drift.internal.driftgl.DriftGL";
//		Files.write(Paths.get(jniJava), g.generateJniJava(cls, eu, cu).toString.bytes, StandardOpenOption.TRUNCATE_EXISTING, StandardOpenOption.CREATE)
//		Files.write(Paths.get(jniCPP), g.generateJniCPP(cls, eu, cu).toString.bytes, StandardOpenOption.TRUNCATE_EXISTING, StandardOpenOption.CREATE)
		
		//println(g.generateSource(e, c))
	}
	

	
	def static void main(String[] args) {
		var path = "C:\\Users\\Christoph\\Projects\\drift\\git\\drift\\org.eclipse.fx.drift.tooling\\gl.xml";
		var outH = '''C:\Users\Christoph\Projects\drift\git\drift\native\lib\DriftGL\include\DriftGL_gen.h'''
		var outCPP = '''C:\Users\Christoph\Projects\drift\git\drift\native\lib\DriftGL\src\DriftGL_gen.cpp'''
		var jniJava = '''C:\Users\Christoph\Projects\drift\git\drift\org.eclipse.fx.drift\src\main\java\org\eclipse\fx\drift\internal\driftgl\DriftGL.java'''
		var jniCPP = '''C:\Users\Christoph\Projects\drift\git\drift\native\lib\DriftGL\src\DriftGL_jni.cpp'''
		
		generateGLProcs(path, outH, outCPP, jniJava, jniCPP);
	}
	
	static def Collected collectGLCore(List<Feature> features) {
		var c = new Collected
		for (f : features) {
			if (f.api == "gl") {
				for (req : f.requires) {
					c.types.addAll(req.types)
					c.enums.addAll(req.enums)
					c.commands.addAll(req.commands)
				}
				for (rem : f.removes) {
					if (rem.profile == "core") {
						c.types.removeAll(rem.types)
						c.enums.removeAll(rem.enums)
						c.commands.removeAll(rem.commands)
					}
				}
			}
		}
		return c
	}
	
	static def show(Collected c) '''
		«FOR t : c.types»
			+ TYPE «t»
		«ENDFOR»
		«FOR e : c.enums»
			+ ENUM «e»
		«ENDFOR»
		«FOR cm : c.commands»
			+ CMD «cm»
		«ENDFOR»
	'''

	static def show(Feature f) '''
		feature «f.api» «f.number» «f.name»
			«FOR r : f.requires»
				«FOR t : r.types»
					+ TYPE «t»
				«ENDFOR»
				«FOR e : r.enums»
					+ ENUM «e»
				«ENDFOR»
				«FOR c : r.commands»
					+ CMD «c»
				«ENDFOR»
			«ENDFOR»
			«FOR r : f.removes»
				«FOR t : r.types»
					- TYPE «t»
				«ENDFOR»
				«FOR e : r.enums»
					- ENUM «e»
				«ENDFOR»
				«FOR c : r.commands»
					- CMD «c»
				«ENDFOR»
			«ENDFOR»
	'''
	
}