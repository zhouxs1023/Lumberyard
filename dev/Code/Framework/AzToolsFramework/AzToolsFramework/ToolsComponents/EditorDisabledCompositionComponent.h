/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/
#pragma once

#include "EditorComponentBase.h"
#include "EditorDisabledCompositionBus.h"

namespace AzToolsFramework
{
    namespace Components
    {
        /**
        * Contains Disabled components to be added to the entity we are attached to.
        */
        class EditorDisabledCompositionComponent
            : public AzToolsFramework::Components::EditorComponentBase
            , public EditorDisabledCompositionRequestBus::Handler
        {
        public:
            AZ_COMPONENT(EditorDisabledCompositionComponent, "{E77AE6AC-897D-4035-8353-637449B6DCFB}", EditorComponentBase);
            static void Reflect(AZ::ReflectContext* context);
            static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& services);
            static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& services);
            ////////////////////////////////////////////////////////////////////
            // EditorDisabledCompositionRequestBus
            AZStd::vector<AZ::Component*> GetDisabledComponents() override;
            void AddDisabledComponent(AZ::Component* componentToAdd) override;
            void RemoveDisabledComponent(AZ::Component* componentToRemove) override;
            ////////////////////////////////////////////////////////////////////

            ~EditorDisabledCompositionComponent() override;
        private:
            ////////////////////////////////////////////////////////////////////
            // AZ::Entity
            void Init() override;
            void Activate() override;
            void Deactivate() override;
            ////////////////////////////////////////////////////////////////////

            AZStd::vector<AZ::Component*> m_disabledComponents;
        };
    } // namespace Components
} // namespace AzToolsFramework