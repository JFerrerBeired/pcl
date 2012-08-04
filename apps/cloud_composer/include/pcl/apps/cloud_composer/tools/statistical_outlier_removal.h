/*
 * Software License Agreement  (BSD License)
 *
 *  Point Cloud Library  (PCL) - www.pointclouds.org
 *  Copyright  (c) 2012, Jeremie Papon.
 *
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Willow Garage, Inc. nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef STATISTICAL_OUTLIER_REMOVAL_H_
#define STATISTICAL_OUTLIER_REMOVAL_H_

#include <pcl/apps/cloud_composer/tool_interface/abstract_tool.h>
#include <pcl/apps/cloud_composer/tool_interface/tool_factory.h>


namespace pcl
{
  namespace cloud_composer
  {
    class StatisticalOutlierRemovalTool : public ModifyItemTool
    {
      Q_OBJECT
      public:
        StatisticalOutlierRemovalTool (PropertiesModel* parameter_model, QObject* parent);
        virtual ~StatisticalOutlierRemovalTool ();
        
        virtual QList <CloudComposerItem*>
        performAction (ConstItemList input_data);
      
        inline virtual QString
        getToolName () const { return "Statistical Outlier Removal Tool";}
    };

    
    class StatisticalOutlierRemovalToolFactory : public QObject, public ToolFactory
    {
      Q_OBJECT
      Q_INTERFACES (pcl::cloud_composer::ToolFactory)
      public:
        ModifyItemTool*
        createTool (PropertiesModel* parameter_model, QObject* parent = 0) 
        {
            return new StatisticalOutlierRemovalTool(parameter_model, parent);
        }
        
        PropertiesModel*
        createToolParameterModel (QObject* parent);
        
        inline virtual QString 
        getPluginName () const { return "Statistical Outlier Removal";}
        
        virtual QString 
        getToolGroupName () const { return "Filters";}
        
        virtual QString
        getIconName () const { return ":/statistical_outlier_removal.png"; }
        
        inline virtual ITEM_TYPES
        getInputItemType () const
        {
          return CLOUD_ITEM;
        }
        
        inline virtual QList <ITEM_TYPES>
        getRequiredInputChildrenTypes () const 
        {
          return QList <ITEM_TYPES> ();
        }
    };



  }
}






#endif //STATISTICAL_OUTLIER_REMOVAL_H_