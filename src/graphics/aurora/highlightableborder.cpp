//
// Created by aqueiros on 18/10/17.
//

#include "src/graphics/aurora/highlightableborder.h"
#include "src/graphics/aurora/textureman.h"


namespace Graphics {
    namespace Aurora {
        HighlightableBorder::HighlightableBorder(const Common::UString &edge, const Common::UString &corner, float x,
                                                 float y, float w, float h,
                                                 const Common::UString &cornerH, const Common::UString &edgeH): BorderQuad(edge, corner, x, y, w, h)
        {
            _edge = TextureMan.get(edge);
            _edgeH = TextureMan.get(edgeH);
            _corner = TextureMan.get(corner);
            _cornerH = TextureMan.get(cornerH);

        }

        HighlightableBorder::~HighlightableBorder() {}

        void HighlightableBorder::render(RenderPass pass) {
            if(isHighlightable() && isHightlighted()){
                setCornerTexture(_cornerH);
                setEdgeTexture(_edgeH);
            } else {
                setCornerTexture(_corner);
                setEdgeTexture(_edge);
            }
            Graphics::Aurora::BorderQuad::render(pass);
        }
    }
}