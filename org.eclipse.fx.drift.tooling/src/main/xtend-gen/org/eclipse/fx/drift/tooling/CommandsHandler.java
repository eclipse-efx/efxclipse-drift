package org.eclipse.fx.drift.tooling;

import com.google.common.base.Objects;
import java.util.Map;
import org.eclipse.fx.drift.tooling.Command;
import org.eclipse.fx.drift.tooling.Param;
import org.eclipse.xtend2.lib.StringConcatenation;
import org.eclipse.xtext.xbase.lib.CollectionLiterals;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

@SuppressWarnings("all")
public class CommandsHandler extends DefaultHandler {
  public Map<String, Command> commands = CollectionLiterals.<String, Command>newHashMap();
  
  private Param curProto = null;
  
  private Param curParam = null;
  
  private Command curCommand = null;
  
  private boolean inCommands = false;
  
  private StringBuilder data = new StringBuilder();
  
  public void characters(final char[] ch, final int start, final int length) throws SAXException {
    String _string = new String(ch, start, length);
    this.data.append(_string);
  }
  
  public void startElement(final String uri, final String localName, final String qName, final Attributes attributes) throws SAXException {
    boolean _matched = false;
    if (Objects.equal(qName, "commands")) {
      _matched=true;
      this.inCommands = true;
    }
    if (!_matched) {
      if (Objects.equal(qName, "command")) {
        _matched=true;
        if (this.inCommands) {
          Command _command = new Command();
          this.curCommand = _command;
        }
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "param")) {
        _matched=true;
        Param _param = new Param();
        this.curParam = _param;
        StringBuilder _stringBuilder = new StringBuilder();
        this.data = _stringBuilder;
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "proto")) {
        _matched=true;
        StringBuilder _stringBuilder_1 = new StringBuilder();
        this.data = _stringBuilder_1;
        Param _param_1 = new Param();
        this.curProto = _param_1;
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "name")) {
        _matched=true;
        boolean _notEquals = (!Objects.equal(this.curProto, null));
        if (_notEquals) {
          this.curProto.type = this.data.toString().trim();
        }
        boolean _notEquals_1 = (!Objects.equal(this.curParam, null));
        if (_notEquals_1) {
          this.curParam.type = this.data.toString().trim();
        }
        StringBuilder _stringBuilder_2 = new StringBuilder();
        this.data = _stringBuilder_2;
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "ptype")) {
        _matched=true;
        StringBuilder _stringBuilder_3 = new StringBuilder();
        this.data = _stringBuilder_3;
      }
    }
  }
  
  public void endElement(final String uri, final String localName, final String qName) throws SAXException {
    boolean _matched = false;
    if (Objects.equal(qName, "commands")) {
      _matched=true;
      this.inCommands = false;
    }
    if (!_matched) {
      if (Objects.equal(qName, "command")) {
        _matched=true;
        if (this.inCommands) {
          Command o = this.commands.put(this.curCommand.name, this.curCommand);
          StringConcatenation _builder = new StringConcatenation();
          _builder.append(" ");
          _builder.append("* ");
          _builder.append(this.curCommand.type, " ");
          _builder.append(" ");
          _builder.append(this.curCommand.name, " ");
          _builder.append("(");
          {
            boolean _hasElements = false;
            for(final Param p : this.curCommand.params) {
              if (!_hasElements) {
                _hasElements = true;
              } else {
                _builder.appendImmediate(", ", " ");
              }
              _builder.append(p.type, " ");
              _builder.append(" ");
              _builder.append(p.name, " ");
            }
          }
          _builder.append(")");
          System.err.println(_builder);
          this.curCommand = null;
        }
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "param")) {
        _matched=true;
        this.curCommand.params.add(this.curParam);
        this.curParam = null;
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "proto")) {
        _matched=true;
        this.curCommand.name = this.curProto.name;
        this.curCommand.type = this.curProto.type;
        this.curProto = null;
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "name")) {
        _matched=true;
        boolean _notEquals = (!Objects.equal(this.curProto, null));
        if (_notEquals) {
          this.curProto.name = this.data.toString();
        }
        boolean _notEquals_1 = (!Objects.equal(this.curParam, null));
        if (_notEquals_1) {
          this.curParam.name = this.data.toString();
        }
      }
    }
    if (!_matched) {
      if (Objects.equal(qName, "ptype")) {
        _matched=true;
        boolean _notEquals_2 = (!Objects.equal(this.curParam, null));
        if (_notEquals_2) {
          this.curParam.type = this.data.toString();
        }
      }
    }
  }
}
