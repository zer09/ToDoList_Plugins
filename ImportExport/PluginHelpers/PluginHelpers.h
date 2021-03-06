#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////

class IPreferences;
class ITaskList14;
class ITransText;

typedef void* HTASKITEM;

////////////////////////////////////////////////////////////////////////////////////////////////

using namespace System;

////////////////////////////////////////////////////////////////////////////////////////////////

#pragma warning( push )
#undef GetProfileInt
#undef GetProfileString

////////////////////////////////////////////////////////////////////////////////////////////////

namespace PluginHelpers
{

////////////////////////////////////////////////////////////////////////////////////////////////

   public ref class CPreferences
   {
   public:
      CPreferences(IPreferences* pPrefs);
      
      int GetProfileInt(String^ sSection, String^ sEntry, int nDefault);
      bool WriteProfileInt(String^ sSection, String^ sEntry, int nValue);

      String^ GetProfileString(String^ sSection, String^ sEntry, String^ sDefault);
      bool WriteProfileString(String^ sSection, String^ sEntry, String^ sValue);

      double GetProfileDouble(String^ sSection, String^ sEntry, double dDefault);
      bool WriteProfileDouble(String^ sSection, String^ sEntry, double dValue);
      
   private:
      IPreferences* m_pPrefs;

   private:
      CPreferences();
   };

////////////////////////////////////////////////////////////////////////////////////////////////

#define DEF_GETTASKVALFUNC(fn, t) t fn(IntPtr hTask)
#define DEF_GETTASKVALFUNC_IDX(fn, t) t fn(IntPtr hTask, int nIndex)

   public ref class CTaskList
   {
   public:
      CTaskList(ITaskList14* pTaskList);        // GET & SET
      CTaskList(const ITaskList14* pTaskList);  // GET ONLY
      
      // GET ----------------------------------------------------

      IntPtr GetFirstTask(IntPtr hParent);
      
      DEF_GETTASKVALFUNC(GetNextTask, IntPtr);
      DEF_GETTASKVALFUNC(GetTaskParent, IntPtr);

      DEF_GETTASKVALFUNC(GetTaskTitle, String^);
      DEF_GETTASKVALFUNC(GetTaskComments, String^);
      DEF_GETTASKVALFUNC(GetTaskAllocatedBy, String^);
      DEF_GETTASKVALFUNC(GetTaskStatus, String^);
      DEF_GETTASKVALFUNC(GetTaskWebColor, String^);
      DEF_GETTASKVALFUNC(GetTaskPriorityWebColor, String^);
      DEF_GETTASKVALFUNC(GetTaskVersion, String^);
      DEF_GETTASKVALFUNC(GetTaskExternalID, String^);
      DEF_GETTASKVALFUNC(GetTaskCreatedBy, String^);
      DEF_GETTASKVALFUNC(GetTaskPositionString, String^);

      DEF_GETTASKVALFUNC(GetTaskID, UInt32);
      DEF_GETTASKVALFUNC(GetTaskColor, UInt32);
      DEF_GETTASKVALFUNC(GetTaskTextColor, UInt32);
      DEF_GETTASKVALFUNC(GetTaskPriorityColor, UInt32);
      DEF_GETTASKVALFUNC(GetTaskPosition, UInt32);
      DEF_GETTASKVALFUNC(GetTaskPriority, UInt32);
      DEF_GETTASKVALFUNC(GetTaskRisk, UInt32);

      DEF_GETTASKVALFUNC(GetTaskCategoryCount, UInt32);
      DEF_GETTASKVALFUNC(GetTaskAllocatedToCount, UInt32);
      DEF_GETTASKVALFUNC(GetTaskTagCount, UInt32);
      DEF_GETTASKVALFUNC(GetTaskDependencyCount, UInt32);
      DEF_GETTASKVALFUNC(GetTaskFileReferenceCount, UInt32);

      DEF_GETTASKVALFUNC_IDX(GetTaskAllocatedTo, String^);
      DEF_GETTASKVALFUNC_IDX(GetTaskCategory, String^);
      DEF_GETTASKVALFUNC_IDX(GetTaskTag, String^);
      DEF_GETTASKVALFUNC_IDX(GetTaskDependency, String^);
      DEF_GETTASKVALFUNC_IDX(GetTaskFileReference, String^);

      DEF_GETTASKVALFUNC(GetTaskPercentDone, Byte);

      DEF_GETTASKVALFUNC(GetTaskLastModified, Int64);
      DEF_GETTASKVALFUNC(GetTaskDoneDate, Int64);
      DEF_GETTASKVALFUNC(GetTaskDueDate, Int64);
      DEF_GETTASKVALFUNC(GetTaskStartDate, Int64);
      DEF_GETTASKVALFUNC(GetTaskCreationDate, Int64);

      DEF_GETTASKVALFUNC(GetTaskDoneDateString, String^);
      DEF_GETTASKVALFUNC(GetTaskDueDateString, String^);
      DEF_GETTASKVALFUNC(GetTaskStartDateString, String^);
      DEF_GETTASKVALFUNC(GetTaskCreationDateString, String^);

      DEF_GETTASKVALFUNC(IsTaskDone, Boolean);
      DEF_GETTASKVALFUNC(IsTaskDue, Boolean);
      DEF_GETTASKVALFUNC(IsTaskGoodAsDone, Boolean);
      
      double GetTaskTimeEstimate(IntPtr hTask, Char% cUnits);
      double GetTaskTimeSpent(IntPtr hTask, Char% cUnits);
      double GetTaskCost(IntPtr hTask);

      Boolean GetTaskRecurrence(IntPtr hTask);

      // SET -----------------------------------------------------
      
      IntPtr NewTask(String^ sTitle, IntPtr hParent);

   private:
      ITaskList14* m_pTaskList;
      const ITaskList14* m_pConstTaskList;

   private:
      CTaskList();
   };

////////////////////////////////////////////////////////////////////////////////////////////////

   public ref class CTransText
   {
   public:
      CTransText(ITransText* pTaskList);
      
      // TODO
      
   private:
      ITransText* m_pTransText;

   private:
      CTransText();
   };


////////////////////////////////////////////////////////////////////////////////////////////////

}

#pragma warning( pop )

