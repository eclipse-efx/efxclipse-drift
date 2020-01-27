package org.eclipse.fx.drift.tooling;

import java.util.List;
import org.eclipse.xtext.xbase.lib.CollectionLiterals;

@SuppressWarnings("all")
public class Require {
  public String comment;
  
  public List<String> types = CollectionLiterals.<String>newArrayList();
  
  public List<String> enums = CollectionLiterals.<String>newArrayList();
  
  public List<String> commands = CollectionLiterals.<String>newArrayList();
}
