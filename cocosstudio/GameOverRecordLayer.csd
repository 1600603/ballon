<GameFile>
  <PropertyGroup Name="GameOverRecordLayer" Type="Layer" ID="fe453c8a-19cf-4e61-a30f-6a7c648fccab" Version="3.10.0.0" />
  <Content ctype="GameProjectContent">
    <Content>
      <Animation Duration="60" Speed="1.0000">
        <Timeline ActionTag="-1255546765" Property="Position">
          <PointFrame FrameIndex="0" X="160.0000" Y="210.0000">
            <EasingData Type="0" />
          </PointFrame>
          <PointFrame FrameIndex="60" X="160.0000" Y="210.0000">
            <EasingData Type="0" />
          </PointFrame>
        </Timeline>
        <Timeline ActionTag="-1255546765" Property="Scale">
          <ScaleFrame FrameIndex="0" X="0.8000" Y="0.8000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="30" X="1.1000" Y="1.1000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="0.8000" Y="0.8000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
        <Timeline ActionTag="-1255546765" Property="RotationSkew">
          <ScaleFrame FrameIndex="0" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
          <ScaleFrame FrameIndex="60" X="0.0000" Y="0.0000">
            <EasingData Type="0" />
          </ScaleFrame>
        </Timeline>
      </Animation>
      <ObjectData Name="Layer" Tag="19" ctype="GameLayerObjectData">
        <Size X="320.0000" Y="425.0000" />
        <Children>
          <AbstractNodeData Name="gameover_boom_1" ActionTag="-1255546765" Tag="32" IconVisible="False" LeftMargin="23.0000" RightMargin="23.0000" TopMargin="112.5000" BottomMargin="107.5000" ctype="SpriteObjectData">
            <Size X="274.0000" Y="205.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="160.0000" Y="210.0000" />
            <Scale ScaleX="0.8000" ScaleY="0.8000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.4941" />
            <PreSize X="0.8562" Y="0.4824" />
            <FileData Type="Normal" Path="png/gameover_boom.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="lblGameOver" ActionTag="-1748330893" Tag="20" IconVisible="False" LeftMargin="68.4539" RightMargin="78.5461" TopMargin="26.2468" BottomMargin="315.7532" ctype="SpriteObjectData">
            <Size X="173.0000" Y="83.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="154.9539" Y="357.2532" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4842" Y="0.8406" />
            <PreSize X="0.5406" Y="0.1953" />
            <FileData Type="Normal" Path="png/gameover_newrecord.png" Plist="" />
            <BlendFunc Src="1" Dst="771" />
          </AbstractNodeData>
          <AbstractNodeData Name="btnReload" ActionTag="-514730052" Tag="23" IconVisible="False" LeftMargin="106.0000" RightMargin="106.0000" TopMargin="350.5230" BottomMargin="20.4770" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="78" Scale9Height="32" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="108.0000" Y="54.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="160.0000" Y="47.4770" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.5000" Y="0.1117" />
            <PreSize X="0.3375" Y="0.1271" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="png/gameover_btn_reload.png" Plist="" />
            <NormalFileData Type="Normal" Path="png/gameover_btn_reload.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="txtPoints" ActionTag="195003048" Tag="25" IconVisible="False" LeftMargin="89.0000" RightMargin="89.0000" TopMargin="171.5000" BottomMargin="166.5000" FontSize="55" LabelText="04411" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="TextObjectData">
            <Size X="142.0000" Y="87.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="160.0000" Y="210.0000" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="160" G="90" B="45" />
            <PrePosition X="0.5000" Y="0.4941" />
            <PreSize X="0.4437" Y="0.2047" />
            <FontResource Type="Normal" Path="fonts/Baloo-Regular.ttf" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="btnHome" ActionTag="1512228196" Tag="22" IconVisible="False" LeftMargin="55.2731" RightMargin="220.7269" TopMargin="290.1555" BottomMargin="95.8445" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="14" Scale9Height="17" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="44.0000" Y="39.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="77.2731" Y="115.3445" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.2415" Y="0.2714" />
            <PreSize X="0.1375" Y="0.0918" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="png/gameover_btn_home.png" Plist="" />
            <NormalFileData Type="Normal" Path="png/gameover_btn_home.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="btnLeaderboard" ActionTag="1425638449" Tag="23" IconVisible="False" LeftMargin="219.7941" RightMargin="56.2059" TopMargin="290.1555" BottomMargin="95.8445" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="14" Scale9Height="17" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="44.0000" Y="39.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="241.7941" Y="115.3445" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.7556" Y="0.2714" />
            <PreSize X="0.1375" Y="0.0918" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="png/gameover_btn_leaderboards.png" Plist="" />
            <NormalFileData Type="Normal" Path="png/gameover_btn_leaderboards.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
          <AbstractNodeData Name="btnShare" ActionTag="450389180" Tag="24" IconVisible="False" LeftMargin="137.5336" RightMargin="138.4664" TopMargin="290.1555" BottomMargin="95.8445" TouchEnable="True" FontSize="14" Scale9Enable="True" LeftEage="15" RightEage="15" TopEage="11" BottomEage="11" Scale9OriginX="15" Scale9OriginY="11" Scale9Width="14" Scale9Height="17" ShadowOffsetX="2.0000" ShadowOffsetY="-2.0000" ctype="ButtonObjectData">
            <Size X="44.0000" Y="39.0000" />
            <AnchorPoint ScaleX="0.5000" ScaleY="0.5000" />
            <Position X="159.5336" Y="115.3445" />
            <Scale ScaleX="1.0000" ScaleY="1.0000" />
            <CColor A="255" R="255" G="255" B="255" />
            <PrePosition X="0.4985" Y="0.2714" />
            <PreSize X="0.1375" Y="0.0918" />
            <TextColor A="255" R="65" G="65" B="70" />
            <DisabledFileData Type="Default" Path="Default/Button_Disable.png" Plist="" />
            <PressedFileData Type="Normal" Path="png/gameover_btn_share.png" Plist="" />
            <NormalFileData Type="Normal" Path="png/gameover_btn_share.png" Plist="" />
            <OutlineColor A="255" R="255" G="0" B="0" />
            <ShadowColor A="255" R="110" G="110" B="110" />
          </AbstractNodeData>
        </Children>
      </ObjectData>
    </Content>
  </Content>
</GameFile>