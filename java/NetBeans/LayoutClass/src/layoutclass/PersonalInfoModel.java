/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package layoutclass;

import java.util.List;
import javax.swing.table.AbstractTableModel;

/**
 *
 * @author iit
 */
public class PersonalInfoModel extends AbstractTableModel {

    private List<PersonalInfo> personalInfoList;
    private String[] columns = {"First Name", "Last Name"};
    public PersonalInfoModel(List<PersonalInfo> info){
        personalInfoList = info;
    }
    @Override
    public int getRowCount() {
        return personalInfoList.size();
        
    }

    @Override
    public int getColumnCount() {
        
        return 2;
    }

    @Override
    public Object getValueAt(int i, int col) {
        PersonalInfo info = personalInfoList.get(i);
    switch(col) {
      case 0: return info.firstName;
      case 1: return info.surName;
      // to complete here...
      default: return null;
    }
    }
    
    public String getColumnName(int col) {
    return columns[col] ;
  }
    
}
