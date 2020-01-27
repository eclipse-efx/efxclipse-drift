package org.eclipse.fx.drift.tooling;

import com.google.common.base.Objects;
import java.util.Map;
import org.eclipse.xtext.xbase.lib.CollectionLiterals;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

@SuppressWarnings("all")
public class EnumHandler extends DefaultHandler {
  public Map<String, org.eclipse.fx.drift.tooling.Enum> enums = CollectionLiterals.<String, org.eclipse.fx.drift.tooling.Enum>newHashMap();
  
  private boolean inEnums;
  
  private org.eclipse.fx.drift.tooling.Enum curEnum;
  
  public void startElement(final String uri, final String localName, final String qName, final Attributes attributes) throws SAXException {
    boolean _matched = false;
    if (Objects.equal(qName, "enums")) {
      _matched=true;
      this.inEnums = true;
    }
    if (!_matched) {
      if (Objects.equal(qName, "enum")) {
        _matched=true;
        if (this.inEnums) {
          org.eclipse.fx.drift.tooling.Enum _enum = new org.eclipse.fx.drift.tooling.Enum();
          this.curEnum = _enum;
          this.curEnum.name = attributes.getValue("name");
          this.curEnum.value = attributes.getValue("value");
        }
      }
    }
  }
  
  public void endElement(final String uri, final String localName, final String qName) throws SAXException {
    boolean _matched = false;
    if (Objects.equal(qName, "enums")) {
      _matched=true;
      this.inEnums = false;
    }
    if (!_matched) {
      if (Objects.equal(qName, "enum")) {
        _matched=true;
        if (this.inEnums) {
          this.enums.put(this.curEnum.name, this.curEnum);
          this.curEnum = null;
        }
      }
    }
  }
}
