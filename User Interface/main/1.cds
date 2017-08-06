<distribution version="15.0.0" name="AmitLaderech" type="MSI">
	<prebuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></prebuild>
	<postbuild>
		<workingdir>workspacedir</workingdir>
		<actions></actions></postbuild>
	<msi GUID="{F3ECF651-A48B-45EC-AB0C-2862E52F2896}">
		<general appName="AmitLaderech" outputLocation="d:\AmitLaderech-User_Interface\User Interface\main\cvidistkit.AmitLaderech" relOutputLocation="cvidistkit.AmitLaderech" outputLocationWithVars="d:\AmitLaderech-User_Interface\User Interface\main\cvidistkit.%name" relOutputLocationWithVars="cvidistkit.%name" upgradeBehavior="1" autoIncrement="true" version="1.0.2">
			<arp company="Afeka Mechatronics Student" companyURL="" supportURL="" contact="" phone="" comments=""/>
			<summary title="" subject="" keyWords="" comments="" author=""/></general>
		<userinterface language="English" showPaths="true" showRuntimeOnly="true" readMe="" license="">
			<dlgstrings welcomeTitle="AmitLaderech" welcomeText=""/></userinterface>
		<dirs appDirID="101">
			<installDir name="[Start&gt;&gt;Programs]" dirID="7" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="AmitLaderech" dirID="100" parentID="7" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="[Program Files]" dirID="2" parentID="-1" isMSIDir="true" visible="true" unlock="false"/>
			<installDir name="AmitLaderech" dirID="101" parentID="2" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="Database" dirID="102" parentID="101" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="panel-progress" dirID="103" parentID="101" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="Pictures" dirID="104" parentID="101" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="progressbar" dirID="105" parentID="101" isMSIDir="false" visible="true" unlock="false"/>
			<installDir name="[Desktop]" dirID="0" parentID="-1" isMSIDir="true" visible="true" unlock="false"/></dirs>
		<files>
			<simpleFile fileID="0" sourcePath="d:\AmitLaderech-User_Interface\User Interface\main\Reports.uir" relSourcePath="Reports.uir" relSourceBase="0" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="1" sourcePath="d:\AmitLaderech-User_Interface\User Interface\main\new-ui-prog.uir" relSourcePath="new-ui-prog.uir" relSourceBase="0" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="2" sourcePath="d:\AmitLaderech-User_Interface\User Interface\main\analytics_functions_demo.uir" relSourcePath="analytics_functions_demo.uir" relSourceBase="0" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="3" sourcePath="d:\AmitLaderech-User_Interface\User Interface\main\1.uir" relSourcePath="1.uir" relSourceBase="0" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="4" sourcePath="d:\AmitLaderech-User_Interface\User Interface\main\email.uir" relSourcePath="email.uir" relSourceBase="0" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="5" sourcePath="d:\AmitLaderech-User_Interface\User Interface\main\ReportsManhe.uir" relSourcePath="ReportsManhe.uir" relSourceBase="0" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="6" sourcePath="d:\AmitLaderech-User_Interface\User Interface\main\ReportsMentor.uir" relSourcePath="ReportsMentor.uir" relSourceBase="0" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="7" sourcePath="d:\AmitLaderech-User_Interface\User Interface\main\request_check.uir" relSourcePath="request_check.uir" relSourceBase="0" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="8" sourcePath="d:\AmitLaderech-User_Interface\User Interface\main\cvibuild.1\Release\1.exe" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="9" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\AmitLaderech.csv" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="10" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Database\._group.ini" targetDir="102" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="11" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Database\._guide.ini" targetDir="102" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="12" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Database\._mentor.ini" targetDir="102" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="13" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Database\._soldier.ini" targetDir="102" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="14" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Database\config.ini" targetDir="102" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="15" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Database\group.ini" targetDir="102" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="16" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Database\guide.ini" targetDir="102" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="17" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Database\mentor.ini" targetDir="102" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="18" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Database\soldier.ini" targetDir="102" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="19" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Database\._config.ini" targetDir="102" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="20" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\panel-progress\0-panel" targetDir="103" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="21" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\panel-progress\12345678-panel" targetDir="103" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="22" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\panel-progress\203994686-panel" targetDir="103" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="23" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Pictures\.DS_Store" targetDir="104" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="24" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Pictures\1203745.jpeg" targetDir="104" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="25" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Pictures\203059936.jpeg" targetDir="104" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="26" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Pictures\23431124.jpeg" targetDir="104" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="27" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\Pictures\HumanShadow.jpg" targetDir="104" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="28" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\progressbar\.DS_Store" targetDir="105" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="29" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\progressbar\12345678-progressbar.png" targetDir="105" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="30" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\progressbar\203994686-progressbar.png" targetDir="105" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="31" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\nconvert.exe" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="32" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\SwithMail.exe" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="33" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\test.bat" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="34" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\processedRecords.txt" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="35" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\panelState.txt" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="36" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\image-10.png" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="37" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\mailimage.png" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/>
			<simpleFile fileID="38" sourcePath="D:\AmitLaderech-User_Interface\User Interface\main\mentor.png" targetDir="101" readonly="false" hidden="false" system="false" regActiveX="false" runAfterInstallStyle="IMMEDIATELY_RESUME_INSTALL" cmdLineArgs="" runAfterInstall="false" uninstCmdLnArgs="" runUninst="false"/></files>
		<fileGroups>
			<projectOutput targetType="0" dirID="101" projectID="0">
				<fileID>8</fileID></projectOutput>
			<projectDependencies dirID="101" projectID="0"/></fileGroups>
		<shortcuts>
			<shortcut name="Amit Laderech System" targetFileID="8" destDirID="100" cmdLineArgs="" description="" runStyle="NORMAL"/>
			<shortcut name="Amit Laderech System" targetFileID="8" destDirID="0" cmdLineArgs="" description="" runStyle="NORMAL"/></shortcuts>
		<mergemodules/>
		<products>
			<product name="NI LabWindows/CVI Shared Runtime 2015" UC="{80D3D303-75B9-4607-9312-E5FC68E5BFD2}" productID="{C123DBC1-8C63-4369-A052-EE7D3922EAC9}" path="C:\ProgramData\National Instruments\MDF\ProductCache\" flavorID="_full_" flavorName="Full" verRestr="false" coreVer="15.0.408">
				<cutSoftDeps>
					<softDep name=".NET Support" UC="{0DDB211A-941B-4125-9518-E81E10409F2E}" depKey="CVI_DotNet.CVI1500.RTE"/>
					<softDep name="ActiveX Container Support" UC="{1038A887-23E1-4289-B0BD-0C4B83C6BA21}" depKey="ActiveX_Container.CVI1500.RTE"/>
					<softDep name="Dev (Patch 1) Support" UC="{C6F76062-CDCB-4931-8580-012AF2152602}" depKey="CVIRTEUpdated.CVI1500.RTE"/>
					<softDep name="Low-Level Driver Support" UC="{20931852-6AA9-4918-926B-130D07A4CF8B}" depKey="CVI_LowLevelDriver.CVI1500.RTE"/>
					<softDep name="Mesa Graphics Support" UC="{5D6378B2-B24D-4AD6-5DA2-FAEFDB81A250}" depKey="Mesa.CVI1500.RTE"/>
					<softDep name="Network Streams Support" UC="{40A5AD7F-4BAF-4A5C-8B56-426B84F75C05}" depKey="CVI_NetworkStreams.CVI1500.RTE"/>
					<softDep name="Network Variable Support" UC="{15CE39FE-1354-484D-B8CA-459077449FB3}" depKey="CVI_NetworkVariable.CVI1500.RTE"/>
					<softDep name="Real-Time Utility Support" UC="{DA6BBF6F-0910-4860-AD46-F14DADF645E9}" depKey="Remote_Configuration.CVI1500.RTE"/>
					<softDep name="TDMS Support" UC="{5A8AF88D-486D-4E30-A7A5-8D8A039BBEBF}" depKey="CVI_Tdms.CVI1500.RTE"/>
					<softDep name="Visual C++ 2008 Redistributable" UC="{BD1E864A-2ACC-4F7E-9A7D-977C39952A52}" depKey="VC2008MSMs_Redist.CVI1500.RTE"/>
					<softDep name="Visual C++ 2008 Runtime" UC="{FDA3F8BB-BAA9-45D7-8DC7-22E1F5C76315}" depKey="VC2008MSMs.CVI1500.RTE"/>
					<softDep name="Visual C++ 2010 Redistributable" UC="{3109870C-C165-4896-AC99-AFDD3CA3304A}" depKey="VC2010MSMs_Redist.CVI1500.RTE"/></cutSoftDeps></product></products>
		<runtimeEngine installToAppDir="false" activeXsup="false" analysis="true" cvirte="true" dotnetsup="false" instrsup="true" lowlevelsup="false" lvrt="true" netvarsup="false" rtutilsup="false">
			<hasSoftDeps/></runtimeEngine><sxsRuntimeEngine>
			<selected>false</selected>
			<doNotAutoSelect>false</doNotAutoSelect></sxsRuntimeEngine>
		<advanced mediaSize="650">
			<launchConditions>
				<condition>MINOS_WINXP_SP0</condition>
			</launchConditions>
			<includeConfigProducts>true</includeConfigProducts>
			<maxImportVisible>silent</maxImportVisible>
			<maxImportMode>merge</maxImportMode>
			<custMsgFlag>false</custMsgFlag>
			<custMsgPath>msgrte.txt</custMsgPath>
			<signExe>false</signExe>
			<certificate></certificate>
			<signTimeURL></signTimeURL>
			<signDescURL></signDescURL></advanced>
		<baselineProducts>
			<product name="NI LabWindows/CVI Shared Runtime 2015" UC="{80D3D303-75B9-4607-9312-E5FC68E5BFD2}" productID="{C123DBC1-8C63-4369-A052-EE7D3922EAC9}" path="(None)" flavorID="_full_" flavorName="Full" verRestr="false" coreVer="15.0.408">
				<dependencies>
					<productID>{0416C950-A8C6-4CFE-B206-A8D28091A40B}</productID>
					<productID>{08505CC2-EA7F-4818-9C45-B74EDA7227F8}</productID>
					<productID>{0CF3F6C3-32FE-45B2-BB99-821B8FB7EBE6}</productID>
					<productID>{108DA20D-E0DA-4F10-A7B6-96D2ACA38752}</productID>
					<productID>{10A1BCD4-CF1D-4198-B037-77FB1AEFF5FE}</productID>
					<productID>{159CE440-D4ED-4F00-B7CE-1686CCC2261F}</productID>
					<productID>{1EDF1337-7E31-4DF4-A4A6-F087B3637732}</productID>
					<productID>{20124E21-206B-485F-838F-14BB88161045}</productID>
					<productID>{21B81C08-8854-4C2D-99E2-6CECA2D468A8}</productID>
					<productID>{22F17C52-A282-4383-8E5C-5C38B41DD605}</productID>
					<productID>{37C0159A-E5E2-4688-9360-0435AE0E55C7}</productID>
					<productID>{3830A103-2D39-4801-927B-BD0C5BC78DC2}</productID>
					<productID>{4ABCECAD-A59C-4FCA-8D4D-7C59242683A1}</productID>
					<productID>{658224F9-1A2B-4E18-B00F-3F969C9EE080}</productID>
					<productID>{7768E152-DF58-48FA-9AEC-074879E0A02E}</productID>
					<productID>{7F93F26A-E5F7-4AE1-840F-F88DFE2DE3A5}</productID>
					<productID>{87E698D6-02AC-485E-A6BA-9194C94CC547}</productID>
					<productID>{A536EF5F-2800-4CE5-A366-3293F6C2D861}</productID>
					<productID>{B3B56C15-80A8-4972-90CB-D80E64B3F39C}</productID>
					<productID>{C1F1FD0A-D051-4CA7-AAF0-2E9C0A881054}</productID>
					<productID>{C23121A8-AF17-4C1D-A2B4-A6DE7A156DCF}</productID>
					<productID>{C67371A2-E288-429E-A2B6-85D36B29BF8E}</productID>
					<productID>{CE1D0ABA-7672-4A48-ACD8-9AFB1EA33809}</productID>
					<productID>{D48821AA-CFF2-4371-A404-34BA2D8D452C}</productID>
					<productID>{DE29136A-18FD-4868-920D-455BAC406C29}</productID>
					<productID>{E84997A1-4D6F-4C0B-B60D-F85B360D2666}</productID>
					<productID>{ECB572E6-5CE3-4E9E-B1B3-16A00E02153A}</productID>
					<productID>{F2273FA7-117C-43D7-BD59-00B025535442}</productID></dependencies></product></baselineProducts>
		<Projects NumProjects="1">
			<Project000 ProjectID="0" ProjectAbsolutePath="d:\AmitLaderech-User_Interface\User Interface\main\1.prj" ProjectRelativePath="1.prj"/></Projects>
		<buildData progressBarRate="1.217064563257796">
			<progressTimes>
				<Begin>0.000000000000000</Begin>
				<ProductsAdded>0.053699750000000</ProductsAdded>
				<DPConfigured>0.766286500000000</DPConfigured>
				<DPMergeModulesAdded>12.678697750000001</DPMergeModulesAdded>
				<DPClosed>17.341197750000003</DPClosed>
				<DistributionsCopied>19.866354250000001</DistributionsCopied>
				<End>82.164909749999993</End></progressTimes></buildData>
	</msi>
</distribution>
